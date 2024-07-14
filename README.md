# 简单的10大排序算法打包+测试项目

### 项目基本架构
- include 运行程序所需的自定义头文件目录
- src 测试以及相关源文件的实现目录
- 具体的源代码功能以及具体实现详见各头文件和源文件，README.md中不再赘述
- CMakeLists.txt 用于对源码进行处理，生成对应的Makefile文件以便最终利用Makefile生成可执行文件

### 建议本地使用Linux终端运行，目前在尝试使用Dockerfile对项目进行打包

- 正在做Docker打包

### Linux端运行流程
- 在项目根目录运行mkdir命令创建本地构建文件夹build并进入
``` shell
mkdir build && cd build
```

- 在build目录中运行CMakeLists.txt文件(cmake版本要求为至少3.16.3，如果版本较低可以修改CMakeLists.txt文件中版本控制的相关命令)
``` shell
cmake ..
```

- 相应的Makefile文件和编译信息生成后，使用make命令进行最终的编译
``` shell
make
```

- 如果想加入任何的调试信息，为了实现运行时和调试时分离，建议利用CMakeLists.txt中定义的调试宏-DDEBUG添加相应的调试输出语句(例如cout，printf等)
``` cmake
add_definitions(-DDEBUG)
```

- 执行make进行项目编译后，最终生成的可执行文件会在build同目录下，直接运行即可(文件名为app，可以在CMakeLists.txt中修改最终生成的文件名以及输出路径)

- 注：项目内有自动的随机数组生成器，调试时可以根据需求修改生成的数组长度以及数组值的取值范围：RandomArray.cc
