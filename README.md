2024年秋学期SDUCS计算机图形学课程实验集合

本课程实验使用的编程语言为CPP，使用的库为OpenGL，使用的编译软件为CLion

实验1：直线的扫描转换

使用Bresenham算法绘制直线，主要在于熟悉Bresenham算法以及熟悉OpenGL的基础用法

实现：ex1-BresenhamLine.cpp
    
    1.绘制网格
    
    2.实时显示线条，绘制时可拖动线条
    
    3.可同时绘制多条直线
    
    4.按空格键可删除最近绘制的线条
    
    5.按动鼠标右键可以选择某一线条的一个端点进行修改


实验2：多边形的扫描转换和区域填充

绘制时要求实时显示多边形，并能填充颜色。

实现：ex2-PolygonScanFilled.cpp
    
    1.实时绘制多边形，绘制时可拖动当前点以及相邻的两条边
    
    2.按动鼠标右键可以实现多边形的颜色填充
    
    3.填充颜色后可以重新绘制多边形，此时会先清空屏幕
    
    4.按动空格键可以清除掉当前屏幕上的内容


实验3：直线裁剪

使用Cohen-Sutherland裁剪算法或梁友栋-Barkey裁剪算法实现直线段的裁剪

实现：ex3-1-Cohen-Sutherland-Clip.cpp,ex3-2-Liang-Barsky-Clip.cpp
    
    1.可实时绘制裁剪窗口，初始时默认为绘制窗口模式
    
    2.可实时绘制直线，能同时绘制多条直线，
    
    3.可实时显示裁剪效果，窗口内的线段为红色，窗口外的线段为青色
   
    4.有四种模式：绘制窗口模式、绘制直线模式、修改直线模式、移动直线模式
   
    5.按键功能：
        
        '1':绘制窗口模式
        
        '2':绘制直线模式
        
        '3':修改直线模式
        
        '4':移动直线模式
      
        '5':删除直线模式
      
        'w''s''a''d':上下左右移动直线
       
        右键：'1'模式与'2'模式相互转换
       
        空格：清空屏幕中所有直线，保留裁剪窗口
       
        Esc：退出


实验4：多边形裁剪

使用Sutherland Hodgman裁剪算法实现多边形裁剪效果。

实现：ex4-0-PolygonClip.cpp
 
    1.可实时绘制裁剪窗口，初始时默认为绘制窗口模式
 
    2.可实时绘制多边形，
   
    3.可实时显示裁剪效果，窗口内的线段为红色，窗口外的线段为青色
   
    4.有四种模式：绘制窗口模式、绘制图形模式、修改顶点模式、删除顶点模式
   
    5.按键功能：
      
        '1':绘制窗口模式
     
        '2':绘制图形模式
    
        '3':修改顶点模式
     
        '4':删除顶点模式
       
        右键：转换地展示裁剪前多边形与展示裁剪后多边形
      
        空格：清空屏幕中的多边形，保留裁剪窗口
      
        Esc：退出

实验5：Bézier曲线

绘制Bézier曲线，可以使用定义法以及递推法(De Casteljau's算法)实现，但定义法不如递推法稳定。

定义法实现：ex5-0-Bézier.cpp

递推法实现：ex5-1-Bézier-De Casteljau's.cpp
    
    1.可实时绘制控制线条，
    
    2.可实时绘制Bézier曲线，
   
    3.有四种模式：绘制线条模式、修改顶点模式、插入顶点模式、删除顶点模式

    4.按键功能：
   
        '1':绘制线条模式
        
        '2':修改顶点模式
        
        '3':插入顶点模式
    
        '4':删除顶点模式
       
        空格：清空屏幕
        
        Esc：退出

实验6：B样条

使用De Boor算法绘制B样条曲线，并能实现阶数变化，初始时默认阶数k=3

实现：ex6-B样条.cpp
  
    1.可实时绘制控制线条，
  
    2.可实时绘制B样条曲线，
    
    3.有四种模式：绘制线条模式、修改顶点模式、插入顶点模式、删除顶点模式
    
    4.按键功能：
        
        'w':绘制线条模式
        
        's':修改顶点模式
    
        'a':插入顶点模式
    
        'd':删除顶点模式
        
        'q':降阶
        
        'e':升阶
        
        '2'-'9':阶数转换为相应数字
        
        空格：清空屏幕
        
        Esc：退出
