// 2025/02/11 19:56:05 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#pragma once


namespace Display
{
    const int PHYSICAL_WIDTH = 1024;
    const int PHYSICAL_HEIGHT = 600;

    void Init();

    void Update();

    void BeginScene(int x = -1, int y = -1);

    void EndScene();
}
