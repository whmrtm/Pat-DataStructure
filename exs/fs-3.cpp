#include <iostream>
#include <limits>
 
using namespace std;
 
class Screen {
private:
    //----�������������Ա
	unsigned int width;
	unsigned int height;
	static Screen* instance;
    // ��Screen���л�ȡ/�ͷ�ͼ�δ�����Դ����һ��RAII����
    //   ����RAII�����Բμ��쳣����Ԫ�Ĳ���
    Screen() {
       // ���������ͼ�ο⣬�򽫳�ʼ��ͼ��ģʽ�ĺ������ڴ˴�
        // initgraph(width_, height_);
    };
    ~Screen () {
        // ���������ͼ�ο⣬�򽫹ر�ͼ��ģʽ�ĺ������ڴ˴�
        // closegraph();
        delete instance;
    }
 
public:    
    //----���� getWidth() �� getHeight() ������
 	int getWidth(){
 		return width;
 	}
 	int getHeight(){
 		return height;
 	}
    static Screen* getInstance(unsigned int width = 640, unsigned int height = 480) {
        // ����ģʽ
        //----���亯����
		 

        if(instance == NULL){
			instance = new Screen();		
			instance->width = width;
			instance->height = height;
		}         	
        return instance;
        
    }
};
 
Screen* Screen::instance = 0;
//----����Screen����������ݳ�Ա��ʼ�����
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
 
// GCC��VC�������ڵ���ģʽ�»���ͣ�����ڲ鿴���н��
#if ( defined(__DEBUG__) || defined(_DEBUG) )
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
#endif
 
  return 0;
}
