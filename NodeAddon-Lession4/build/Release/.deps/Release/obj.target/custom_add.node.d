cmd_Release/obj.target/custom_add.node := g++ -shared -pthread -rdynamic -m64  -Wl,-soname=custom_add.node -o Release/obj.target/custom_add.node -Wl,--start-group Release/obj.target/custom_add/oop_demo_factory/Add.o Release/obj.target/custom_add/oop_demo_factory/add_bind.o -Wl,--end-group 
