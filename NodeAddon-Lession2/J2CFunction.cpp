//
// Created by goerver on 16-6-16.
//

#include <node/node.h>
#include <node/v8.h>

namespace J2Function{
    using v8::Exception;
    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Number;
    using v8::Object;
    using v8::String;
    using v8::Value;

    //定义一个函数，实现一个加法
    //输入的参数是通过调用FunctionCallbackInfo<Value>& args获取的
    void Add(const FunctionCallbackInfo<Value>& args){
        Isolate* isolate = args.GetIsolate();

        if(args.Length()>2){
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate,"Wrong number of args")));
            return;
        }

        //因为Javascript是弱类型的，对JS传过来的值需要进行类型判断
        if(!args[0]->IsNumber() || !args[1]->IsNumber())
        {
            isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate,"Wrong arguments")));
            return;
        }

        //执行加法操作
        double value = args[0]->NumberValue()+
                       args[1]->NumberValue();

        //定义一个V8 Number
        Local<Number> num = Number::New(isolate,value);

        //通过FunctionCallbackInfo<Value>&类型参数设置返回值
        args.GetReturnValue().Set(num);
    }

    //初始化函数,绑定函数方法名 如绑定方法名为 'cadd'
    void Init(Local<Object> exports){
        NODE_SET_METHOD(exports,"cadd",Add);
    }

    //绑定到V8,NODE_MODULE是一个宏定义,
    // 添加过程是一系列的执行过程
    //NODE_MODULE(modname, regfunc)
    NODE_MODULE(j2c_add,Init);
}