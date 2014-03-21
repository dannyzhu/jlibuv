package test;


import java.nio.ByteBuffer;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

import com.oracle.libuv.*;
import com.oracle.libuv.cb.*;
import com.oracle.libuv.handles.*;

public class UDPEchoServerTest {
    public void start() throws Throwable {
        final AtomicInteger clientSendCount = new AtomicInteger(0);
        final AtomicInteger serverRecvCount = new AtomicInteger(0);

        final AtomicBoolean serverDone = new AtomicBoolean(false);
        final AtomicBoolean clientDone = new AtomicBoolean(false);

        final LoopHandle loop = new LoopHandle();
        final UDPHandle server = new UDPHandle(loop);

        server.setRecvCallback(new UDPRecvCallback() {
            @Override
            public void onRecv(int nread, ByteBuffer data, Address address) throws Exception {
                server.send(data, address.getPort(), address.getIp());
            }
        });

        server.setSendCallback(new UDPSendCallback() {
            @Override
            public void onSend(int status, Exception error) throws Exception {
            }
        });

        server.setThrowableCallback(new UDPThrowableCallback() {
            @Override
            public void onThrowable(Throwable e) {
                e.printStackTrace();
            }
        });

        server.bind(3333, "0.0.0.0");
        server.recvStart();

        loop.run();

    }

    public static void main(String[] args) throws Throwable {
        System.out.println("libuv version : " + LibUV.version());
        UDPEchoServerTest test = new UDPEchoServerTest();
        test.start();
    }
}
