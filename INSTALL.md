### Cpp Project Template 编译和安装

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
make install

```

执行完以上，即可在/path/to/install目录下生成bin、lib、include3个目录。

注意：运行demo程序bin/cppunit_demo_main时，需要在当前目录放置tulip-log的日志配置文件logger.conf ，同时该目录下要已经创建好logs 目录供输出文件名滚动的日志文件。logger.conf文件示例见misc/config/logger.conf 。



### 其它

相关细节或其它未尽事宜，可联系 dingbinthu@163.com 探讨咨询。