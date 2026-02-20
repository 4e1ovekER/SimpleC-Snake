#ifndef UTILITIES_H
#define UTILITIES_H

#include <Windows.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <thread>
#include <utility>
#include <array>
#include <random>

//******************Typedefs, Constexprs, & Defines******************
#define IS_DOWN(b) inputs.buttons[b].is_down
/**
 * @def IS_DOWN(b)
 * @brief Проверяет, зажата ли клавиша в текущем кадре
 * @param b Индекс клавиши для проверки
 * @return true если клавиша зажата
 */
#define PRESSED(b) inputs.buttons[b].is_down && inputs.buttons[b].changed
 /**
  * @def PRESSED(b)
  * @brief Проверяет, была ли клавиша нажата в этом кадре
  * @param b Индекс клавиши для проверки
  * @return true если клавиша была нажата именно в этом кадре
  */

typedef unsigned int uint32;

// VK codes
constexpr uint32 VK_A = 0x41;
constexpr uint32 VK_B = 0x42;
constexpr uint32 VK_C = 0x43;
constexpr uint32 VK_D = 0x44;
constexpr uint32 VK_E = 0x45;
constexpr uint32 VK_F = 0x46;
constexpr uint32 VK_G = 0x47;
constexpr uint32 VK_H = 0x48;
constexpr uint32 VK_I = 0x49;
constexpr uint32 VK_J = 0x4A;
constexpr uint32 VK_K = 0x4B;
constexpr uint32 VK_L = 0x4C;
constexpr uint32 VK_M = 0x4D;
constexpr uint32 VK_N = 0x4E;
constexpr uint32 VK_O = 0x4F;
constexpr uint32 VK_P = 0x50;
constexpr uint32 VK_Q = 0x51;
constexpr uint32 VK_R = 0x52;
constexpr uint32 VK_S = 0x53;
constexpr uint32 VK_T = 0x54;
constexpr uint32 VK_U = 0x55;
constexpr uint32 VK_V = 0x56;
constexpr uint32 VK_W = 0x57;
constexpr uint32 VK_X = 0x58;
constexpr uint32 VK_Y = 0x59;
constexpr uint32 VK_Z = 0x5A;
/**
 * @brief Виртуальные коды клавиш A-Z (0x41-0x5A)
 * @details Используются для обработки нажатий клавиш
 */
 /**
  * @brief Ширина тайловой карты в количестве тайлов
  */

// tilemap
constexpr int tilemapSizeX = 15;
constexpr int tilemapSizeY = 15;

/**
 * @struct RenderState
 * @brief Хранит состояние рендерера
 * @var RenderState::width
 *   Ширина окна в пикселях
 * @var RenderState::height
 *   Высота окна в пикселях
 * @var RenderState::memory
 *   Указатель на буфер пикселей
 * @var RenderState::bitmap_info
 *   Информация о битмапе для Windows
 */

// colors
constexpr uint32 LIGHTGREEN = 0x007a21;
/**
 * @brief Светло-зеленый цвет для тайлов
 */
constexpr uint32 SLIGHTLYDARKGREEN = 0x00b515;
/**
 * @brief Чуть темнее зеленый для градиента
 */
constexpr uint32 DARKGREEN = 0x0f3814;
/**
 * @brief Темно-зеленый для фона
 */

constexpr uint32 DARKERGREEN = 0x003900;
/**
 * @brief Еще темнее зеленый для границ
 */
constexpr uint32 DARKESTGREEN = 0x002000;
/**
 * @brief Самый темный зеленый для шапки
 */
constexpr uint32 BEAUTIFULBLUE = 0x262afd;
/**
 * @brief Синий цвет для специальных тайлов
 */
constexpr uint32 APPLERED = 0xfc0140;
/**
 * @brief Красный цвет для специальных тайлов
 */


//******************Typedefs, Constexprs, & Defines******************

//******************Structs/Classes******************
struct RenderState {
	int width, height;
	void* memory;
	BITMAPINFO bitmap_info;
};
//******************Structs/Classes******************

//******************Functions*****************
uint32 calculateTileColor(const int xPos, const int yPos);
/**
 * @brief Возвращает текущий FPS
 * @return Количество кадров в секунду
 */
int getFPS();
/**
 * @brief Возвращает состояние тика для анимаций
 * @return true если четный тик, false если нечетный
 */
bool getTickState();
/**
 * @brief Ограничивает значение между минимумом и максимумом
 * @tparam T1 Тип минимального значения
 * @tparam T2 Тип значения для ограничения
 * @tparam T3 Тип максимального значения
 * @param min Минимальное допустимое значение
 * @param val Значение для ограничения
 * @param max Максимальное допустимое значение
 * @return Ограниченное значение
 */


template <typename T1, typename T2, typename T3> inline T2 clamp(T1 min, T2 val, T3 max) {
	if		(val < min) return static_cast<T2>(min);
	else if (val > max) return static_cast<T2>(max);
	else				return val;
}
/**
 * @brief Текущее состояние рендерера для отрисовки
 */
//******************Functions******************

//******************Global Variables******************
extern RenderState renderer;
/**
 * @brief Флаг работы программы
 * @details true - программа работает, false - программа завершается
 */
extern bool running;
/**
 * @brief Масштаб отрисовки всех элементов
 */
extern float scale;
/**
 * @brief Масштаб скорости по X для анимаций и движения
 */
extern float velocityScaleX;
/**
 * @brief Масштаб скорости по Y для анимаций и движения
 */
extern float velocityScaleY;
/**
 * @brief Двумерный массив [15][15] с цветами всех тайлов карты
 */
extern std::array<std::array<uint32, tilemapSizeY>, tilemapSizeX> tilemap;
/**
 * @brief Номер текущего запуска/кадра для анимаций
 */
extern uint32 runNumber;
//******************Global Variables******************

#endif