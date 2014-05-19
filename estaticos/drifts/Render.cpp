void Drifts::Render(){
	SDL_RenderClear(Renderer);
	SDL_Surface *image = IMG_Load("C:/Users/homepc/Downloads/rod/prog/drifts/estaticos/images/test.jpg");
	if ( !image ){
      std::cout<<"IMG_Load: "<<IMG_GetError();
      return;
    }
    SDL_Rect rcDest = { 0, 0, 0, 0 };
    SDL_BlitSurface ( image, NULL, PrimarySurface, &rcDest );
    SDL_Texture * testura = SDL_CreateTextureFromSurface(Renderer, image);
    SDL_FreeSurface ( image );
    


    SDL_RenderCopy(Renderer, testura, NULL, NULL);
    
	SDL_RenderPresent(Renderer);
}