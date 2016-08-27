{
    "targets":[
        {
            "target_name":"object_factory",
            "sources":["object_factory.cpp"]
        },
        {
            "target_name":"function_factory",
            "sources":["function_factory.cpp"]
        },
        {
            "target_name":"wrap_oop",
             "sources": [
                    "oop_demo/object_bind.cpp",
                    "oop_demo/CustomObject.cpp"
                  ]
        },
         {
               "target_name": "custom_add",
               "sources": [
                  "oop_demo_factory/Add.cpp",
                   "oop_demo_factory/add_bind.cpp"
                ]
         },
         {
              "target_name": "function_add_by_obj",
              "sources": [
              "oop_demo_passing_wrap/AddObj.cpp",
              "oop_demo_passing_wrap/bind_add_obj.cpp"
              ]
         },
         {
              "target_name": "function_callback",
              "sources": [
              "add_function_async.cpp",
              ]
         }
    ]
}