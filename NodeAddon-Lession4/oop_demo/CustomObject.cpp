//
// Created by goerver on 16-6-22.
// welcome http:://www.flyfishonline.com
//

#include "CustomObject.h"

namespace quit{
    using v8::Context;
    using v8::Function;
    using v8::FunctionCallbackInfo;
    using v8::FunctionTemplate;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::Persistent;
    using v8::String;
    using v8::Value;

    Persistent<Function> CustomObject::constructor;

    CustomObject::CustomObject(double value) : value_(value) {};
    CustomObject::~CustomObject() {}

    //该类中的`Init`　方法，将也V8绑定初始化对象
    void CustomObject::Init(Local<Object> exports) {
        Isolate *isolate = exports->GetIsolate();

        //Prepare constructor template
        //初始构造函数

        //绑定该类的创建方法为 New方法
        Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
        tpl->SetClassName(String::NewFromUtf8(isolate, "CustomObject"));
        tpl->InstanceTemplate()->SetInternalFieldCount(1);
        // 函数原型　方法添加
        NODE_SET_PROTOTYPE_METHOD(tpl, "plusOne", PlusOne);

        constructor.Reset(isolate, tpl->GetFunction());

        //将函数挂载到exports对象上去
        exports->Set(String::NewFromUtf8(isolate, "CustomObject"),
                     tpl->GetFunction());

    }

    void CustomObject::New(const v8::FunctionCallbackInfo<v8::Value>& args) {
        Isolate *isolate = args.GetIsolate();

        if (args.IsConstructCall()) {
            //调用初始化构函数
            double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
            CustomObject *obj = new CustomObject(value);
            obj->Wrap(args.This());
            args.GetReturnValue().Set(args.This());
        } else {
            //调用 function 'CustomObject'的构造函数
            const int argc = 1;
            Local<Value> argv[argc] = {args[0]};
            Local<Context> context = isolate->GetCurrentContext();
            //绑定初始化构造函数
            Local<Function> cons = Local<Function>::New(isolate, constructor);
            //创建一个v8::Object对象
            Local<Object> result = cons->NewInstance(context, argc, argv).ToLocalChecked();

            args.GetReturnValue().Set(result);
        }
    }

    void CustomObject::PlusOne(const v8::FunctionCallbackInfo<v8::Value>& args) {
        Isolate *isolate = args.GetIsolate();
        //关键处,需要记住.
        //为什么不是直接写成value_++,然后设置返回值？当看到static 关键字，估计就知道了。
        CustomObject *obj = node::ObjectWrap::Unwrap<CustomObject>(args.Holder());
        obj->value_ += 1;

        args.GetReturnValue().Set(Number::New(isolate, obj->value_));
    }
}
