//
// Created by http://flyfishonline.com @author orangebook
// Object factory
#include<node/node.h>

namespace demo{
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void CreateObject(const FunctionCallbackInfo<Value> &args)
    {
        Isolate* isolate = args.GetIsolate();

        Local<Object> obj = Object::New(isolate);
        //设置obj对象的toString字段值为 `创建对象时的参数`
        obj->Set(String::NewFromUtf8(isolate,"toString"),args[0]->ToString());
        //获取返回值对象后，设置obj
        args.GetReturnValue().Set(obj);
    }

    void Init(Local<Object> exports,Local<Object> moudle){
        // 　创建绑定CreateObject函数到exprots对象上来
        NODE_SET_METHOD(moudle,"exprots",CreateObject);
    }

        //注册该对象的对应的函数
    NODE_MODULE(object_factory,Init);
}





