#ifndef PLATFORM_COMMANDS_H
#define PLATFORM_COMMANDS_H

#include "utilities.h"
#include "renderer.h"
#include "object_manager.h"

struct Input;

/**
@brief Представляет состояние отдельной кнопки/клавиши ввода
Структура отслеживает текущее состояние кнопки и факт её изменения
с момента последнего кадра/обновления.
*/
struct ButtonState
{
	bool is_down = false;  
	bool changed = false;  
};

/**
@brief Перечисление всех возможных игровых действий (кнопок управления)
Определяет виртуальные кнопки, которые используются в игровой логике,
абстрагируясь от конкретных клавиш клавиатуры.
*/
enum {
	BUTTON_MOVEUP,     
	BUTTON_MOVEDOWN,   
	BUTTON_MOVELEFT,   
	BUTTON_MOVERIGHT,  

	BUTTON_COUNT       
};

/**
@brief Главная структура ввода, агрегирующая состояние всех кнопок
Содержит массив состояний для всех виртуальных кнопок игры.
Используется для централизованного доступа к состоянию ввода.
*/
struct Input {
	std::array<ButtonState, BUTTON_COUNT> buttons;  /**< Массив состояний всех кнопок */
};

/**
@brief Получает состояние конкретной клавиши из системного сообщения
@param vk_code Виртуальный код клавиши Windows (VK_*)
@param is_down Флаг, указывающий, нажата ли клавиша (true) или отпущена (false)
@param window Указатель на окно, получившее сообщение (может использоваться для дополнительной проверки)
*/
void getKeyStates(uint32& vk_code, bool& is_down, HWND* window);

/**
@brief Обрабатывает ввод с клавиатуры и обновляет состояния виртуальных кнопок
Транслирует физические нажатия клавиш в игровые действия (BUTTON_*),
обновляя соответствующие структуры ButtonState.
@param vk_code Виртуальный код нажатой/отпущенной клавиши
@param is_down true если клавиша нажата, false если отпущена
*/
void inputProcessing(uint32 vk_code, bool is_down);

/**
@brief Обновляет скорость игрока на основе текущего состояния ввода
Использует состояния виртуальных кнопок (BUTTON_MOVE*), чтобы изменить
вектор скорости объекта игрока. Обычно вызывается каждый кадр в цикле обновления.
@param player Ссылка на объект игрока, скорость которого будет изменена
*/
void updateVelocityFromInputs(PlayerObject& player);

/** 
@brief Глобальный экземпляр структуры ввода, хранящий текущее состояние всех кнопок 
*/
extern Input inputs;

#endif 