# jlibuv #
===

libuv for java

#### Examples: UDP Echo Server ####
---
```Java

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

        server.bind(3333, "0.0.0.0");
        server.recvStart();

        loop.run();

```

#### Examples: TCP Echo Server ####
---

Coming soon!
