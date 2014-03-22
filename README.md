jlibuv 
======

libuv for java

#### Examples: UDP Echo Server
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

        server.setThrowableCallback(new UDPThrowableCallback() {
            @Override
            public void onThrowable(Throwable e) {
                e.printStackTrace();
            }
        });

        server.bind(3333, "0.0.0.0");
        server.recvStart();

        loop.run();

```

#### Examples: TCP Echo Server
---
```Java

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

```

#### Examples: TCP Echo Client
---
```Java

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

```