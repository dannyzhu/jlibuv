#########################################################################
# File Name: c.mac.sh
# Author: Danny
# Mail: dannyzhu@gmail.com
# Created Time: 五  3/21 10:25:04 2014
#########################################################################
#!/bin/bash

export CLASSPATH=out/bin:$CLASSPATH

javah -d out/include com.oracle.libuv.handles.AsyncHandle    
javah -d out/include com.oracle.libuv.handles.CheckHandle     
javah -d out/include com.oracle.libuv.handles.FileEventHandle     
javah -d out/include com.oracle.libuv.handles.FilePollHandle     
javah -d out/include com.oracle.libuv.handles.Handle     
javah -d out/include com.oracle.libuv.handles.IdleHandle     
javah -d out/include com.oracle.libuv.handles.LoopCallbackHandler     
javah -d out/include com.oracle.libuv.handles.LoopCallbackHandlerFactory     
javah -d out/include com.oracle.libuv.handles.LoopHandle     
javah -d out/include com.oracle.libuv.handles.PipeHandle     
javah -d out/include com.oracle.libuv.handles.ProcessHandle     
javah -d out/include com.oracle.libuv.handles.SignalHandle     
javah -d out/include com.oracle.libuv.handles.StdioOptions     
javah -d out/include com.oracle.libuv.handles.StreamHandle     
javah -d out/include com.oracle.libuv.handles.TCPHandle     
javah -d out/include com.oracle.libuv.handles.TimerHandle     
javah -d out/include com.oracle.libuv.handles.TTYHandle     
javah -d out/include com.oracle.libuv.handles.UDPHandle     
javah -d out/include com.oracle.libuv.Constants
javah -d out/include com.oracle.libuv.NativeException
javah -d out/include com.oracle.libuv.Files
javah -d out/include com.oracle.libuv.LibUV
