#include <node/node.h>
#include <node/v8.h>

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void Method(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        Local<Object> arg_obj = Local<Object>::Cast(args[0]);
        Local<Value> str = arg_obj->Get(String::NewFromUtf8(isolate,"name"));

        Local<Object> fool = Object::New(isolate);
        if(str->IsString())
            fool->Set (String::NewFromUtf8 (isolate,"name"),str->ToString() );
        else
        fool->Set (String::NewFromUtf8 (isolate,"name"),String::NewFromUtf8(isolate,"gods") );
        fool->Set (String::NewFromUtf8 (isolate,"age"), v8::Integer::New(isolate,21));
        fool->Set (String::NewFromUtf8 (isolate,"jobs"), v8::Array::New (isolate));
        Local<Object> jobs = fool->Get (String::NewFromUtf8 (isolate,"jobs"))->ToObject ();
        jobs->Set (0, String::NewFromUtf8 (isolate,"SEU"));
        jobs->Set (1, String::NewFromUtf8 (isolate,"Taobao"));

        args.GetReturnValue().Set(fool);
    }

    void Init(Local<Object> module) {
        NODE_SET_METHOD(module, "tojson", Method);
    }

    NODE_MODULE(binding, Init)

