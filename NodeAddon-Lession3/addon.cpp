//
// Created by http://www.flyfishonline.com on 16-6-16.
// addon.cpp
#include <node/node.h>
#include <node/v8.h>
namespace demo {

    using v8::Function;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Null;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void RunCallback(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        //获取JS中的回调函数，并强制转换
        Local<Function> cb = Local<Function>::Cast(args[0]);
        const unsigned argc = 1;
        //创建一个返回值,名称任意
        Local<Value> argv[argc] = { String::NewFromUtf8(isolate, "hello world") };
        //调用传过来的回调函数，返回值
        cb->Call(Null(isolate), argc, argv);
    }

    void Init(Local<Object> exports, Local<Object> module) {
        NODE_SET_METHOD(module, "exports", RunCallback);
    }

    NODE_MODULE(addon, Init)
}  // namespace demo
