#include "ImageResize.h"

int ImageResize::tempHandle = 0;

ImageResize::ImageResize() {
}

ImageResize::~ImageResize() {
}

int ImageResize::Resize(int handle, int sizeX, int sizeY) {

	if (handle != -1) {//画像のロードに成功した場合
		int Nowscreen = GetDrawScreen();//現在の描画対象画面を一時保存
		int miniHandle = MakeScreen(sizeX, sizeY, TRUE);//1/10サイズのグラフィックハンドルを作成
		if (miniHandle == -1) {//ハンドル作成に失敗した場合
			return handle;
		}
		SetDrawScreen(miniHandle);//描画対象画面を先ほど作った1/10サイズのグラフィックハンドルに変更
		DrawExtendGraph(0, 0, sizeX, sizeY, handle, TRUE);//ロードした画像を1/10サイズで描画
		DeleteGraph(handle);//不要になった本来のサイズのグラフィックハンドルを削除
		SetDrawScreen(Nowscreen);//現在の描画対象画面を元の画面に戻す
		return miniHandle;//縮めた画像のグラフィックハンドルを返す
	}
	else {//画像のロードに失敗した場合
		return -1;//エラー発生を示す-1を返す
	}
}
