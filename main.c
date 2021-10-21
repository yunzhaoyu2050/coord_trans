#include <stdio.h>
#include "coordtrans.h"

int main(void) {
  // 初始化配置信息
  struct ConfigParam cfp = {
    .dx = 0,  // x坐标平移量(米)
    .dy = 0,  // y坐标平移量(米)
    .dz = 0,  // z坐标平移量(米)
    .wx = 0,  // x坐标旋转角度(秒)
    .wy = 0,  // y坐标旋转角度(秒)
    .wz = 0,  // z坐标旋转角度(秒)
    .k = 0,  // 尺度因子(ppm)，这里其实应该用变量m表示
    .height = 0,  // 投影面高程
    .gcsSrc = WGS84,  // 原始坐标系
    .gcsDst = WGS84,  // 结果坐标系
  };
  // 初始化常用椭球参数信息
  DatumEllipsoidal(118, 0, NULL); // 初始化中央子午线118

  /* 测试 */
  printf("test1->\r\n");
  struct Point d2p_i = {37.404744476, 118.105194481, 0.000000000000};
  struct Point d2p_res = d2p(&d2p_i, &cfp); // 大地坐标转平面坐标
  printf("WGS84->WGS84(大地坐标转平面坐标)[原始坐标]:b:%lf, l:%lf, h:%lf\r\n", d2p_i.x, d2p_i.y, d2p_i.z);
  printf("WGS84->WGS84(大地坐标转平面坐标)[目的坐标]:x:%lf, y:%lf, h:%lf\r\n", d2p_res.x, d2p_res.y, d2p_res.z);

  struct Point p2d_i;
  p2d_i.x = d2p_res.x;
  p2d_i.y = d2p_res.y;
  p2d_i.z = d2p_res.z;
  struct Point p2d_res = p2d(&p2d_i, &cfp); // 大地坐标转平面坐标
  printf("WGS84->WGS84(平面坐标转大地坐标)[原始坐标]:b:%lf, l:%lf, h:%lf\r\n", p2d_i.x, p2d_i.y, p2d_i.z);
  printf("WGS84->WGS84(平面坐标转大地坐标)[目的坐标]:x:%lf, y:%lf, h:%lf\r\n", p2d_res.x, p2d_res.y, p2d_res.z);

  printf("test2->\r\n");
  struct Point d2p_i1 = {37.500176375, 118.100050313, 0.000000000000};
  struct Point d2p_res1 = d2p(&d2p_i1, &cfp); // 大地坐标转平面坐标
  printf("WGS84->WGS84(大地坐标转平面坐标)[原始坐标]:b:%lf, l:%lf, h:%lf\r\n", d2p_i1.x, d2p_i1.y, d2p_i1.z);
  printf("WGS84->WGS84(大地坐标转平面坐标)[目的坐标]:x:%lf, y:%lf, h:%lf\r\n", d2p_res1.x, d2p_res1.y, d2p_res1.z);

  struct Point p2d_i2;
  p2d_i2.x = d2p_res1.x;
  p2d_i2.y = d2p_res1.y;
  p2d_i2.z = d2p_res1.z;
  struct Point p2d_res2 = p2d(&p2d_i2, &cfp); // 大地坐标转平面坐标
  printf("WGS84->WGS84(平面坐标转大地坐标)[原始坐标]:b:%lf, l:%lf, h:%lf\r\n", p2d_i2.x, p2d_i2.y, p2d_i2.z);
  printf("WGS84->WGS84(平面坐标转大地坐标)[目的坐标]:x:%lf, y:%lf, h:%lf\r\n", p2d_res2.x, p2d_res2.y, p2d_res2.z);
  return 0;
}