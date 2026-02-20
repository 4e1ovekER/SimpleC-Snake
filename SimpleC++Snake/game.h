#ifndef GAME_H
#define GAME_H

#include "utilities.h"
#include "renderer.h"
#include "platform_commands.h"
#include "object_manager.h"

/**
@brief главный класс игры, содержащий всю основную игровую логику
@params отвечает за инициализацию, обработку ввода, обновление состояния,
отрисовку и завершение игры (game over).
 */
class Game
{
private:
    ObjectManager* objectManager;  
    FoodObject* food;           
    PlayerObject* player;         
    ScoreObject* score;         

    HWND* window;                  
    HDC* hdc;                     
    int   finalScore;              

public:
    /**
    @brief конструктор класса Game
    Инициализирует все необходимые указатели на объекты игры и Win32-ресурсы.
    @param window указатель на HWND игрового окна
    @param hdc указатель на HDC (контекст устройства) для отрисовки
    @param objectManager указатель на менеджер объектов
    @param food указатель на объект еды
    @param player указатель на объект игрока
    @param score указатель на объект счёта
    */
    Game(HWND* window, HDC* hdc, ObjectManager* objectManager,
        FoodObject* food, PlayerObject* player, ScoreObject* score);

    /**
    @brief деструктор класса
    выполняет очистку, если требуется (в текущей реализации может быть пустым).
    */
    ~Game();

    /**
    @brief возвращает финальное количество очков игрока
    @return int финальное значение счёта
    @note значение актуально только после вызова gameover().
    @params до завершения игры возвращает либо 0, либо некорректное значение.
     */
    inline int getScore() { return finalScore; }

    /**
    @brief Инициализация игрового состояния
    выполняет начальную расстановку объектов, сброс счёта,
    создание первой еды и другие подготовительные действия.
    */
    void init();

    /**
    @brief обработка состояния проигрыша (game over)
    Фиксирует финальный счёт, останавливает игровую логику,
    может показывать экран окончания игры.
    */
    void gameOver();

    /**
    @brief Обработка пользовательского ввода
    @params считывает и обрабатывает нажатия клавиш (обычно стрелки),
    изменяет направление движения игрока и т.д.
    */
    void input();

    /**
    @brief обновление игрового состояния (основной игровой цикл)
    @params выполняет всю игровую логику: движение игрока, проверку столкновений,
    съедание еды, появление новой еды, увеличение счёта и т.д.
    */
    void update();

    /**
    @brief отрисовка текущего кадра игры
    @params передаёт информацию об объектах в рендерер и выполняет вывод на экран.
    */
    void draw();
};

#endif