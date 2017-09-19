#include "ImageProcessor.h"

#pragma unmanaged
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using cv::Mat;
#include <random>

namespace OpenCVApp {

	template <typename T>
	void ImageProcessor::toSafeValue(T min, T* value, T max) {

		*value = std::max(min, *value);
		*value = std::min(max, *value);

	}

	/**
	* @brief <Handson EX1> 画像をリードする。
	* @param path 画像ファイルのパス
	* @param out Mat形式の画像の書き出し先
	* @detail 画像はCV_8UC3形式のフルカラー画像として読み込まれる。
	*/
	void ImageProcessor::readImage(const std::string& path, cv::Mat* out) {
		*out = cv::imread(path, cv::IMREAD_COLOR); 
	}
	bool ImageProcessor::writeImage(const std::string& path, const cv::Mat* in) {
		return cv::imwrite(path, *in);
		
 	}

	const int MaxWitdh::BRIGHTNESS = 255;
	/**
	* @brief <Handson EX2> 画像のRGBの毎の明るさを変更する。
	* @param src 変換元の画像
	* @param r 赤色の明るさ ( -MaxWitdh::BRIGHTNESS <= r <= MaxWitdh::BRIGHTNESS )
	* @param g 緑色の明るさ ( -MaxWitdh::BRIGHTNESS <= g <= MaxWitdh::BRIGHTNESS )
	* @param b 青色の明るさ ( -MaxWitdh::BRIGHTNESS <= b <= MaxWitdh::BRIGHTNESS )
	* @param dst 変換先の画像
	* @detail srcをrgb毎のMatに分解し、それぞれの明るさを変更する。
	*/
	void ImageProcessor::changeBrightness(const cv::Mat* src, int r, int g, int b, cv::Mat* dst) {
		toSafeValue<int>(-MaxWitdh::BRIGHTNESS, &r, MaxWitdh::BRIGHTNESS);
		toSafeValue<int>(-MaxWitdh::BRIGHTNESS, &g, MaxWitdh::BRIGHTNESS);
		toSafeValue<int>(-MaxWitdh::BRIGHTNESS, &b, MaxWitdh::BRIGHTNESS);

		std::vector<cv::Mat> rgb;

		split(*src, rgb);

		rgb[0] += b;
		rgb[1] += g;
		rgb[2] += r;

		merge(rgb, *dst);
	}

	const int MaxLevel::BLUR = 10;
	/**
	* @brief <Handson EX3> 画像にぼかし効果を加える。
	* @param src 変換元の画像
	* @param level 効果のレベル ( 0 <= level <=  MaxLevel::BLUR )
	* @param dst 変換先の画像
	* @detail levelに比例してぼかしの効果は強くなる。
	*/
	void ImageProcessor::blur(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::BLUR);

		int sideSize = 3 + level * 2;
		cv::GaussianBlur(*src, *dst, cv::Size(sideSize, sideSize), 0.1 + level);
	}

	const int MaxLevel::SHARPNESS = 10;
	/**
	* @brief <Handson EX4> 画像に鮮鋭化効果を加える。
	* @param src 変換元の画像
	* @param level 効果のレベル ( 0 <= level <=  MaxLevel::SHARPNESS )
	* @param dst 変換先の画像
	* @detail levelに比例して鮮鋭化効果は強くなる。
	*/
	void ImageProcessor::sharpen(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::SHARPNESS);

		int sideSize = 3 + (level / 2) * 2; /* levelの増加に応じて、3,3, 5,5, 7 ・・・と増える*/
		int centerIndex = sideSize / 2;

		/* 鮮鋭化フィルタ */
		Mat kernel(sideSize, sideSize, CV_64F);

		double sumReduceElement = -0.8 * (level + 1); /* 減算する要素数の合計 */
		double centerElement = -sumReduceElement + 1;

		int sidecount = sideSize / 2;
		/**
		 * 1画素当たりの減算する要素数
		 * 合計が、sumReduceElementとなるよう、ループ内で中心からの距離に応じて帳尻合わせをする。
		 */
		double localReduceElement = sumReduceElement / (8.0 * sidecount);

		for (int y = 0; y < sideSize; y++) {
			for (int x = 0; x < sideSize; x++) {
				if (y == centerIndex && x == centerIndex) {
					kernel.at<double>(centerIndex, centerIndex) = centerElement;
					continue;
				}
				/* 中心からのチェス盤距離 */
				int distanceFromCenter = std::max(std::abs(y - centerIndex), std::abs(x - centerIndex));
				kernel.at<double>(y, x) = localReduceElement / distanceFromCenter;
			}
		}

		int defaultDepth = -1;
		cv::filter2D(*src, *dst, defaultDepth, kernel);
	}

	const int MaxLevel::PENCIL = 10;
	/**
	* @brief <Handson EX5.1> 画像を黒鉛筆で描いたような線画画像に変換する。
	* @param src 変換元の画像
	* @param level 効果のレベル ( 0 <= level <=  MaxLevel::PENCIL )
	* @param dst 変換先の画像
	* @detail 画像からエッジを検出することで、画像内の輪郭を検出する。
	* 輪郭を黒、背景を白とすることで、線画画像を得る。
	* levelに比例して多くのエッジを検出する。
	*/
	void ImageProcessor::drawWithPenclil(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::PENCIL);

		cv::cvtColor(*src, *dst, CV_RGB2GRAY);

		double topThreash = 200.0 - level * 20.0;
		double bottomThreash = 150.0 - level * 15.0;

		cv::Canny(*dst, *dst, topThreash, bottomThreash);

		cv::cvtColor(*dst, *dst, CV_GRAY2RGB);
		*dst = ~*dst;
	}

	/**
	* @brief <Handson EX5.2> 画像を色鉛筆で描いたようなフルカラーの線画画像に変換する。
	* @param src 変換元の画像
	* @param level 効果のレベル ( 0 <= level <=  MaxLevel::PENCIL )
	* @param dst 変換先の画像
	* @detail 白黒の線画を作成し、マスクとすることでフルカラーの線画画像を作成する。
	*/
	void ImageProcessor::drawWithColorPenclil(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::PENCIL);

		Mat mask;
		drawWithPenclil(src, level, &mask);

		*dst = (*src + mask);
	}

	const int MaxLevel::OIL_PAINT = 10;
	/**
	* @brief <Handson EX6> 画像を油絵で書いたようなクラスタリングされた画像に変換する。
	* @param src 変換元の画像
	* @param level 効果のレベル ( 0 <= level <=  MaxLevel::OIL_PAINT )
	* @param dst 変換先の画像
	* @detail levelに比例して、クラスタリングの幅が拡大する。(大雑把なクラスタリングになる。)
	*/
	void ImageProcessor::toOilPaint(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::OIL_PAINT);

		float windowWidth = 2.0f * level;
		float colorWidth = 5.0f * level;

		cv::pyrMeanShiftFiltering(*src, *dst, windowWidth, colorWidth);
	}


#define RAND(max) (rand() % (max))
#define DOUBLE_RAND() (((double) rand() * 2.0 / (double) RAND_MAX) - 1.0)
	const int MaxLevel::SNOW_STORM = 200;
	/**
	* @brief <Handson EX7> 画像に吹雪のような効果を加える。
	* @param src 変換元の画像
	* @param level 効果のレベル ( 0 <= level <=  MaxLevel::SNOW_STORM )
	* @param dst 変換先の画像
	* @detail levelに比例して、多くの雪が描画される。
	* 雪の位置、形状は、アフィン変換により規則性とランダム性を持って決定される。
	*/
	void ImageProcessor::causeSnowStorm(const cv::Mat* src, int level, cv::Mat* dst) {
		toSafeValue<int>(0, &level, MaxLevel::SNOW_STORM);
		src->copyTo(*dst);

		srand((unsigned) time(NULL));

		Mat circle(20, 20, CV_8UC3, cv::Scalar(0));
		cv::circle(circle, cv::Point(10, 10), 5, cv::Scalar(200, 150, 150), -1, CV_AA);
		ImageProcessor::blur(&circle, 1, &circle);
		Mat canvas(src->size(), CV_8UC3);

		for (int i = 0; i < level; i++) {
			canvas = cv::Scalar(0);
			
			double angle = std::_Pi / 4.0; /* π/4 (45°)を基準に */
			angle += DOUBLE_RAND() * std::_Pi / 10; /* 左右に最大π/ 18 (10°)回転 */

			double ratio = 0.5 + 0.5 * DOUBLE_RAND(); /* 0.5 ～ 1.0の倍率 */
			double height = 1.0 * ratio;
			double width = 2.0 * ratio;
			/*
			 * | sin -cos |   | w 0 |   | w*sin -h*cos |
			 * | cos  sin | X | 0 h | = | w*cos  h*sin |
			**/
			Mat matrix = (cv::Mat_<double>(2, 3) <<
				width * std::sin(angle), -height * std::cos(angle), RAND(src->cols),
				width * std::cos(angle),  height * std::sin(angle), RAND(src->rows));
			
			cv::warpAffine(circle, canvas, matrix, src->size(), cv::INTER_LINEAR, cv::BORDER_TRANSPARENT);
			*dst += canvas;
		}

	}


	

	const int MaxLevel::DETECTION = 10;
	/**
	* @brief <Handson EX8> 画像の中から目的の物体を含む矩形を検出し、物体矩形を描画する。
	* @param src 変換元の画像
	* @param level 効果のレベル ( 0 <= level <=  MaxLevel::DETECTION )
	* @param cascade 物体検出のためのカスケード分類器クラスのオブジェクト
	* @param minNeighbors 物体候補となる矩形に必要な、最小の近傍矩形数( 1 <= minNeighbors)
	* @param dst 変換先の画像
	* @detail levelに比例して、精密に物体検出を行う。
	* 検出する物体は引数のcascadeに依存する。
	*/
	void ImageProcessor::detectObject(const cv::Mat* src, int level, cv::Mat* dst, cv::CascadeClassifier* cascade, int minNeighbors) {
		toSafeValue<int>(0, &level, MaxLevel::DETECTION);
		toSafeValue<int>(1, &minNeighbors, 0x7ffffff );

		double scaleFactor = 1.55 - 0.5 * (level / (double) MaxLevel::DETECTION);

		src->copyTo(*dst);
		
		Mat graySubject;
		cv::cvtColor(*src, graySubject, cv::COLOR_BGR2GRAY);

		std::vector<cv::Rect> rects;
	
		cascade->detectMultiScale(graySubject, rects, scaleFactor, minNeighbors);

		for (auto rect : rects) {
			cv::rectangle(*dst, rect, cv::Scalar(100,255,100), 2);
		}
	}

	const int MaxLevel::ORIGINAL = 10;
	/**
	* @brief <Handson EXα> 画像にオリジナルのエフェクトを加える。
	* @param src 変換元の画像
	* @param level 効果のレベル ( 0 <= level <=  MaxLevel::ORIGINAL )
	* @param dst 変換先の画像
	* @detail levelに比例して、オリジナルのエフェクトが加わる。
	*/
	void ImageProcessor::applyOriginalEffect(const cv::Mat* src, int level, cv::Mat* dst) {
		src->copyTo(*dst);
	}
}