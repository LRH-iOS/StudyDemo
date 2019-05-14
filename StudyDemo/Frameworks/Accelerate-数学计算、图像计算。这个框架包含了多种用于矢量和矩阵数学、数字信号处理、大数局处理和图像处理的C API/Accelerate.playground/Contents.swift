/**
 * Accelerate进行大规模的数学计算和图像计算更容易。因此，它被广泛应用于机器学习程序中。这个框架包含了多种用于矢量和矩阵数学、数字信号处理、大数局处理和图像处理的C API。
 */
import UIKit
import Accelerate


var x: [Float] = [1, 2, 3]
var y: [Float] = [4, 5, 6]

//10x + y
//用来计算向量乘以常数
//向量中元素的个数
//常数
//“x”向量
//“x”向量的步长（例如如果INCX是7，第七个使用）
//“y”向量
//y向量的步长
cblas_saxpy(3, 100, &x, 1, &y, 1)
y
x
