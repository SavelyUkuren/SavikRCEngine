#include <iostream>

#include "engine/engine.h"
#include "testGame/TestScene.h"

int main()
{
    engine e("Test", 1280, 800);

    TestScene *testScene = new TestScene();
    e.setScene(testScene);

    e.start();

    return 0;
}
