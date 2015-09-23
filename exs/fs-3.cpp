#include <iostream>
#include <limits>
 
using namespace std;
 
class Screen {
private:
    //----补充多个数据域成员
	unsigned int width;
	unsigned int height;
	static Screen* instance;
    // 在Screen类中获取/释放图形窗口资源，是一种RAII方法
    //   关于RAII，可以参见异常处理单元的材料
    Screen() {
       // 如果启用了图形库，则将初始化图形模式的函数置于此处
        // initgraph(width_, height_);
    };
    ~Screen () {
        // 如果启用了图形库，则将关闭图形模式的函数置于此处
        // closegraph();
        delete instance;
    }
 
public:    
    //----补充 getWidth() 与 getHeight() 函数，
 	int getWidth(){
 		return width;
 	}
 	int getHeight(){
 		return height;
 	}
    static Screen* getInstance(unsigned int width = 640, unsigned int height = 480) {
        // 单例模式
        //----补充函数体
		 

        if(instance == NULL){
			instance = new Screen();		
			instance->width = width;
			instance->height = height;
		}         	
        return instance;
        
    }
};
 
Screen* Screen::instance = 0;
//----补充Screen类的特殊数据成员初始化语句
//instance = new Screen();
//instance = Screen::getInstance();
int main() {
    int width, height;
    Screen* screen = 0;
	
    cin >> width >> height;
    
    screen = Screen::getInstance(width, height);
//    screen = Screen::getInstance();
 
    cout << screen->getWidth() << " " <<
                 screen->getHeight() << endl;
 
// GCC及VC编译器在调试模式下会暂停，便于查看运行结果
#if ( defined(__DEBUG__) || defined(_DEBUG) )
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
#endif
 
  return 0;
}
