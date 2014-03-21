package test;

import com.oracle.libuv.Address;
import com.oracle.libuv.LibUV;
import com.oracle.libuv.cb.*;
import com.oracle.libuv.handles.LoopHandle;
import com.oracle.libuv.handles.StreamHandle;
import com.oracle.libuv.handles.TCPHandle;
import com.oracle.libuv.handles.UDPHandle;

import java.nio.ByteBuffer;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * Created by Danny on 14-03-21.
 */
public class TCPEchoServerTest {
    public void start() throws Throwable {
        final AtomicInteger clientSendCount = new AtomicInteger(0);
        final AtomicInteger serverRecvCount = new AtomicInteger(0);

        final AtomicBoolean serverDone = new AtomicBoolean(false);
        final AtomicBoolean clientDone = new AtomicBoolean(false);

        final LoopHandle loop = new LoopHandle();
        final TCPHandle server = new TCPHandle(loop);

        server.setConnectCallback(new StreamConnectCallback() {
            @Override
            public void onConnect(int status, Exception error) throws Exception {
                System.out.println("on connect");
            }
        });

        server.setConnectionCallback(new StreamConnectionCallback() {
            @Override
            public void onConnection(int status, Exception error) throws Exception {
                final TCPHandle peer = new TCPHandle(loop);
                server.accept(peer);
                System.out.println("peer connect from address : " + peer.getPeerName());
                peer.readStart();
                peer.setReadCallback(new StreamReadCallback() {
                    @Override
                    public void onRead(ByteBuffer data) throws Exception {
                        if (data != null && data.limit() > 0)
                        {
                            peer.write(data);
                        }else{
                            peer.close();
                        }
                    }
                });

                peer.setCloseCallback(new StreamCloseCallback() {
                    @Override
                    public void onClose() throws Exception {
                        System.out.println("peer close");
                    }
                });

                peer.setWriteCallback(new StreamWriteCallback() {
                    @Override
                    public void onWrite(int status, Exception error) throws Exception {
                    }
                });

                peer.setThrowableCallback(new StreamThrowableCallback() {
                    @Override
                    public void onThrowable(Throwable e) {
                        System.out.println("peer on throwable");
                        e.printStackTrace();
                    }
                });

            }
        });

        server.setCloseCallback(new StreamCloseCallback() {
            @Override
            public void onClose() throws Exception {
                System.out.println("server close");
            }
        });

        server.bind("0.0.0.0", 3333);
        server.listen(0);

        loop.run();

    }

    public static void main(String[] args) throws Throwable {
        System.out.println("libuv version : " + LibUV.version());
        TCPEchoServerTest test = new TCPEchoServerTest();
        test.start();
    }

}
