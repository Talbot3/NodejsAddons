// created by http://flyfishonline.com @author orangebook
//
#include <node/node.h>

namespace function{
    using v8::Function;
    using v8::FunctionCallbackInfo;
    using v8::FunctionTemplate;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    //定义返回的函数
    void ToString(const FunctionCallbackInfo<Value>& args)
    {
        Isolate* isolate = args.GetIsolate();
        //设置函数的返回值为函数　
        args.GetReturnValue().Set(args[0]->ToString());
    }

    void CreateFunction(const FunctionCallbackInfo<Value> &args)
    {
        Isolate* isolate = args.GetIsolate();

        //创建一个模板方法，并绑定返回的函数
        Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate,ToString);
        //获取函数
        Local<Function> fn = tpl->GetFunction();
        //绑定函数的名称，必须个有唯性
        fn->SetName(String::NewFromUtf8(isolate,"function.ToString"));
        //设置返回值为　函数
        args.GetReturnValue().Set(fn);
    }

    void Init(Local<Object> exports,Local<Object> module)
    {
        NODE_SET_METHOD(module,"exports",CreateFunction);
    }

    NODE_MODULE(function_return,Init);

}

