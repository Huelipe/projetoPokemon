

namespace ray {
  #include <raylib.h>
};

int main (){
  ray::InitWindow(1280, 720, "Primeiros passos com a Raylib");

  ray::Texture sprite, bg;
  sprite = ray::LoadTexture("./sprite.png");
  bg = ray::LoadTexture("./bg.png");

  float posx = -sprite.width;

  while( !ray::WindowShouldClose() ){

    posx += 0.9f;
    if( posx > 1280 ){
     posx = -sprite.width; 
    }

    ray::BeginDrawing(); 
    ray::ClearBackground(ray::WHITE);
     ray::DrawText("Primeiros passos com a Raylib", 50, 100, 50, ray::BLACK);
     ray::DrawTexture(bg, 0, 0, ray::WHITE);
     ray::DrawTexture(sprite, posx, 630 - sprite.height, ray::WHITE);
    ray::EndDrawing();
  }

  ray::CloseWindow();

  return 0;
}