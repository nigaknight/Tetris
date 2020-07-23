#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>

using namespace sf;

// ���ֶ���˹����ı�ʾ
int block[7][4] = {
	1, 3, 5, 7,
	2, 4, 5, 7,
	3, 5, 4, 6,
	3, 5, 4, 7,
	2, 3, 5, 7,
	3, 5, 7, 6,
	2, 3, 4, 5,
};

// ����˹������ͼ���е�����
struct Point {
	int x;
	int y;
} curBlock [4];

// ��ǰ���������
int blockIndex;

// ����һ���·���
void newBlock() {
	blockIndex = rand() % 7 + 1;
	int n = blockIndex - 1;
	for (int i = 0; i < 4; i++) {
		curBlock[i].x = block[n][i] % 2;
		curBlock[i].y = block[n][i] / 2;
	}
}

int main() {

	// �������������
	srand(time(0));

	// ���ý���
	RenderWindow window(VideoMode(340, 409), "Wjy-2020");

	// ���ر���ͼƬ������
	Texture t1;
	t1.loadFromFile("Image/background.jpg");
	Sprite spriteBg(t1);
	window.draw(spriteBg);

	// ��ʾ����
	window.display();

	system("pause");
	return 0;
}