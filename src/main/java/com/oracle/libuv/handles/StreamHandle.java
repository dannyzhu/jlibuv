/*
 * Copyright (c) 2013, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

package com.oracle.libuv.handles;

import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;
import java.util.Objects;

import com.oracle.libuv.cb.*;

public class StreamHandle extends Handle {

    protected boolean closed;
    private boolean readStarted;

    private StreamReadCallback onRead = null;
    private StreamRead2Callback onRead2 = null;
    private StreamWriteCallback onWrite = null;
    private StreamConnectCallback onConnect = null;
    private StreamConnectionCallback onConnection = null;
    private StreamCloseCallback onClose = null;
    private StreamShutdownCallback onShutdown = null;
    private StreamThrowableCallback onThrowable = null;

    static {
        _static_initialize();
    }

    public void setReadCallback(final StreamReadCallback callback) {
        onRead = callback;
    }

    public void setRead2Callback(final StreamRead2Callback callback) {
        onRead2 = callback;
    }

    public void setWriteCallback(final StreamWriteCallback callback) {
        onWrite = callback;
    }

    public void setConnectCallback(final StreamConnectCallback callback) {
        onConnect = callback;
    }

    public void setConnectionCallback(final StreamConnectionCallback callback) {
        onConnection = callback;
    }

    public void setCloseCallback(final StreamCloseCallback callback) {
        onClose = callback;
    }

    public void setShutdownCallback(final StreamShutdownCallback callback) {
        onShutdown = callback;
    }

    public void setThrowableCallback(final StreamThrowableCallback callback) {
        onThrowable = callback;
    }

    public void readStart() {
        if (!readStarted) {
            _read_start(pointer);
        }
        readStarted = true;
    }

    public void read2Start() {
        if (!readStarted) {
            _read2_start(pointer);
        }
        readStarted = true;
    }

    public void readStop() {
        _read_stop(pointer);
        readStarted = false;
    }

    public int write2(final String str, final StreamHandle handle) {
        return _write2(str, handle);
    }

    public int write2(final String str, final UDPHandle handle) {
        return _write2(str, handle);
    }

    private int _write2(final String str, final Handle handle) {
        Objects.requireNonNull(str);
        assert handle != null;
        final byte[] data;
        try {
            data = str.getBytes("utf-8");
        } catch (final UnsupportedEncodingException e) {
            throw new RuntimeException(e); // "utf-8" is always supported
        }
        return _write2(pointer, ByteBuffer.wrap(data), data, 0, data.length, handle.pointer, loop.getContext());
    }

    public int write(final String str) {
        Objects.requireNonNull(str);
        final byte[] data;
        try {
            data = str.getBytes("utf-8");
        } catch (final UnsupportedEncodingException e) {
            throw new RuntimeException(e); // "utf-8" is always supported
        }
        return write(ByteBuffer.wrap(data), 0, data.length);
    }

    public int write(final String str, final String encoding) throws UnsupportedEncodingException {
        Objects.requireNonNull(str);
        final byte[] data = str.getBytes(encoding);
        return write(ByteBuffer.wrap(data), 0, data.length);
    }

    public int write(final ByteBuffer buffer, final int offset, final int length) {
        Objects.requireNonNull(buffer);
        return buffer.hasArray() ?
                _write(pointer, buffer, buffer.array(), offset, length, loop.getContext()) :
                _write(pointer, buffer, null, offset, length, loop.getContext());
    }

    public int write(final ByteBuffer buffer) {
        Objects.requireNonNull(buffer);
        return write(buffer, 0, buffer.capacity());
    }

    public int closeWrite() {
        return _close_write(pointer, loop.getContext());
    }

    public void close() {
        if (!closed) {
            _close(pointer);
        }
        closed = true;
    }

    public int listen(final int backlog) {
        return _listen(pointer, backlog);
    }

    public int accept(final StreamHandle client) {
        return _accept(pointer, client.pointer);
    }

    public boolean isReadable() {
        return _readable(pointer);
    }

    public boolean isWritable() {
        return _writable(pointer);
    }

    public long writeQueueSize() {
        return _write_queue_size(pointer);
    }

    protected StreamHandle(final long pointer, final LoopHandle loop) {
        super(pointer, loop);
        this.closed = false;
        this.readStarted = false;
        _initialize(pointer);
    }

    @Override
    protected void finalize() throws Throwable {
        close();
        super.finalize();
    }

    private void callRead(final ByteBuffer data) {
        if (onRead != null) {
            if (onThrowable == null) {
                loop.getCallbackHandler().handleStreamReadCallback(onRead, data);
            } else {
                try {
                    onRead.onRead(data);
                } catch (Throwable e) {
                    if (onThrowable != null) {
                        onThrowable.onThrowable(e);
                    } else {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    private void callRead2(final ByteBuffer data, long handle, int type) {
        if (onRead2 != null) {
            if (onThrowable == null) {
                loop.getCallbackHandler().handleStreamRead2Callback(onRead2, data, handle, type);
            } else {
                try {
                    onRead2.onRead2(data, handle, type);
                } catch (Throwable e) {
                    if (onThrowable != null) {
                        onThrowable.onThrowable(e);
                    } else {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    private void callWrite(final int status, final Exception error, final Object context) {
        if (onWrite != null) {
            if (onThrowable == null) {
                loop.getCallbackHandler(context).handleStreamWriteCallback(onWrite, status, error);
            } else {
                try {
                    onWrite.onWrite(status, error);
                } catch (Throwable e) {
                    if (onThrowable != null) {
                        onThrowable.onThrowable(e);
                    } else {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    private void callConnect(final int status, final Exception error, final Object context) {
        if (onConnect != null) {
            if (onThrowable == null) {
                loop.getCallbackHandler(context).handleStreamConnectCallback(onConnect, status, error);
            } else {
                try {
                    onConnect.onConnect(status, error);
                } catch (Throwable e) {
                    if (onThrowable != null) {
                        onThrowable.onThrowable(e);
                    } else {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    private void callConnection(final int status, final Exception error) {
        if (onConnection != null) {
            if (onThrowable == null) {
                loop.getCallbackHandler().handleStreamConnectionCallback(onConnection, status, error);
            } else {
                try {
                    onConnection.onConnection(status, error);
                } catch (Throwable e) {
                    if (onThrowable != null) {
                        onThrowable.onThrowable(e);
                    } else {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    private void callClose() {
        if (onClose != null) {
            if (onThrowable == null) {
                loop.getCallbackHandler().handleStreamCloseCallback(onClose);
            } else {
                try {
                    onClose.onClose();
                } catch (Throwable e) {
                    if (onThrowable != null) {
                        onThrowable.onThrowable(e);
                    } else {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    private void callShutdown(final int status, final Exception error, final Object context) {
        if (onShutdown != null) {
            if (onThrowable == null) {
                loop.getCallbackHandler(context).handleStreamShutdownCallback(onShutdown, status, error);
            } else {
                try {
                    onShutdown.onShutdown(status, error);
                } catch (Throwable e) {
                    if (onThrowable != null) {
                        onThrowable.onThrowable(e);
                    } else {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    private static native void _static_initialize();

    private native void _initialize(final long ptr);

    private native void _read_start(final long ptr);

    private native void _read2_start(final long ptr);

    private native void _read_stop(final long ptr);

    private native boolean _readable(final long ptr);

    private native boolean _writable(final long ptr);

    private native int _write(final long ptr,
                              final ByteBuffer buffer,
                              final byte[] data,
                              final int offset,
                              final int length,
                              final Object context);

    private native int _write2(final long ptr,
                               final ByteBuffer buffer,
                               final byte[] data,
                               final int offset,
                               final int length,
                               final long handlePointer,
                               final Object context);

    private native long _write_queue_size(final long ptr);

    private native void _close(final long ptr);

    private native int _close_write(final long ptr, final Object context);

    private native int _listen(final long ptr, final int backlog);

    private native int _accept(final long ptr, final long client);

}
