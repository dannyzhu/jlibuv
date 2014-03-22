package test;

import com.oracle.libuv.LibUV;
import com.oracle.libuv.cb.StreamCloseCallback;
import com.oracle.libuv.cb.StreamConnectCallback;
import com.oracle.libuv.cb.StreamReadCallback;
import com.oracle.libuv.handles.LoopHandle;
import com.oracle.libuv.handles.TCPHandle;

import java.nio.ByteBuffer;

/**
 * Created by Danny on 14-03-22.
 */
public class TCPClientTest {
    public static void main(String[] args) throws Throwable {

        final LoopHandle loop = new LoopHandle();
        final TCPHandle client = new TCPHandle(loop);

        client.setConnectCallback(new StreamConnectCallback() {
            @Override
            public void onConnect(int status, Exception error) throws Exception {
                System.out.println("on connect");
                client.readStart();
                client.write(ByteBuffer.wrap("okok".getBytes()));
            }
        });

        client.setCloseCallback(new StreamCloseCallback() {
            @Override
            public void onClose() throws Exception {
                System.out.println("on close");
            }
        });

        client.setReadCallback(new StreamReadCallback() {
            @Override
            public void onRead(ByteBuffer data) throws Exception {
                System.out.println("on read : " + data);
                client.write(data);
            }
        });

        client.connect("127.0.0.1", 3333);

        loop.run();
    }
}
