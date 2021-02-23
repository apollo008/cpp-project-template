### CppProjTemplate：c++ 工程初始模板简介

CppProjTemplate是一个简易精炼的C++工程的模板项目，该项目清晰地设置了一个典型C++项目工程的较为推荐的源码目录结构。用户只需通过git从github下载后做一些极其简单的修改后，就可以在此代码结构目录下添加和编写自己的代码模块，轻松支持C++单元测试编码框架。它具有以下优势：

1. 工程整体采用支持跨平台的CMake 构建工具构建而成，移植性好，CMake语法简洁易用，后续添加和编辑代码模板构建易用。
2. 工程已经包含和支持作者自研的开源的成熟稳定的日志系统 [tulip-log](https://github.com/apollo008/tulip-log), Github地址：[https://github.com/apollo008/tulip-log](https://github.com/apollo008/tulip-log) ，打印日志功能强大而易用。
3. 工程已经包含和支持一套设计好的cppunit模块的代码使用方式，使得用户能非常方便地添加自己的cppunit test代码模块，而不用去费劲精力搭建cppunit代码运行框架。src/main/cppunit_demo文件夹下已经给出了一些常用的cppunit test的编写方法。推荐的cppunit test编写方法参见src/main/cppunit_demo/demo/test/calculator_unittest.h 和src/main/cppunit_demo/demo/test/calculator_unittest.cpp。
4. 用法简述：用户从github上下载本工程源码后，只需将src/main/cppunit_demo文件夹 拷贝成自己新的业务模块文件夹，参考其内部目录布局和cmake/cppunittest使用方法即可。



### 编译和安装

目前支持类Unix环境下编译安装，CppProjectTemplate 项目依赖的第三方库有：
- tulip-log
- cppunit 

编译安装CppProjectTemplate之前先要安装以上2个依赖库。

具体编译和安装方法如下：

```
git clone https://github.com/apollo008/cpp-proj-template.git cpp-proj-template.git
cd cpp-proj-template.git
vim src/CMakeLists.txt 
搜索need to set 发现存在第3行和第11行，依次修改如下：
第3行： set(TOP_PROJECT_NAME cppunitdemo) 将cppunitdemo改为你的实际项目名称
第11行： set(${TOP_PROJECT_NAME_UPPER}_DEPEND_PREFIX_DIR /path/to/install/share) 将/path/to/install/share改为share库的安装路径，比如${HOME}/local,注意确保该路径有写权限。修改之后后续不要再改变该路径。

mkdir build-dir
cd build-dir
#安装依赖
cmake -DENABLE_BUILD_SHARE=ON ../src
执行完以上这一步即可完成依赖库。注意不需要再执行make 和make install了。

接下来编译安装CppProjTemplateDemo,这里以cppunit demo为例展示cpp 项目目录结构，包含单元测试。
#安装CppProjTemplateDemo
首先保持根目录下CMakeLists.txt第11行修改的内容不再改变；
cd build-dir
rm -rf *
cmake -DCMAKE_INSTALL_PREFIX=/path/to/install  ../src
make -j10
#此时 运行ctest 命令可以执行所有的单元测试
make install

```

执行完以上，即可在/path/to/install目录下生成bin、lib、include3个目录。

注意：运行demo程序bin/cppunit_demo_main时，需要在当前目录放置tulip-log的日志配置文件logger.conf ，同时该目录下要已经创建好logs 目录供输出文件名滚动的日志文件。logger.conf文件示例见misc/config/logger.conf 。

在build-dir目录下执行ctest，运行结果如下：

![image-20210223155157934](https://raw.githubusercontent.com/apollo008/picgo/master/img/20210223155157.png)

查看本地的Testing/Temporary/LastTest.log可看到具体的fail细节。

### 其它

相关细节或其它未尽事宜，可联系 dingbinthu@163.com 探讨咨询。

