# Foundation


## .apinotes文件作用
简单介绍：映射oc中的语法到swift中
官方介绍：
API注释提供了一种机制，通过这种机制，可以使用原始的Objective-C头中不存在的附加语义信息对Objective-C API进行注释。
然后，Swift编译器可以在导入相应的Objective-C模块时使用这些语义信息，以便更好地将Objective-C API映射到Swift中。
API注释被组织成一组.apiNotes文件。每个.apiNotes文件都包含单个Objective-C模块的注释，这些注释是用clang存储库中描述的yaml（fixme:to be）编写的。
当swift编译器导入相应的框架时，这些yaml源代码被惰性地加载，如下所述。
要为还没有API注释的系统模块$module添加API注释，请创建新的源文件$module.apiNotes并更新cmakeLists.txt。在下一次生成期间，生成系统将找到更新的API注释。


