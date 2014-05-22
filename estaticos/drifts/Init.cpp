bool Init(){
//+++++++++++++++++ INITIALIZING VIDEO ++++++++++++++++++++++++++++++++++++//
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        Log("Unable to Init SDL: %s", SDL_GetError());
        return false;
    }
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        Log("Unable to Init hinting: %s", SDL_GetError());
    }
//+++++++++++++++++ END INIT VIDEO ++++++++++++++++++++++++++++++++++++++++//

//+++++++++++++++++ CREATING WINDOW +++++++++++++++++++++++++++++++++++++++//
    if((Window = SDL_CreateWindow(
        "Drifts",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)
    ) == NULL) {
        Log("Unable to create SDL Window: %s", SDL_GetError());
        return false;
    }
//+++++++++++++++++ END WINDOW +++++++++++++++++++++++++++++++++++++++++++//

//+++++++++++++++++ RENDERING WINDOW +++++++++++++++++++++++++++++++++++++//
    if((Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
        Log("Unable to create renderer");
        return false;
    }

    SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);
//+++++++++++++++++ END RENDERING +++++++++++++++++++++++++++++++++++++++//

//+++++++++++++++++ INITIALIZING PNG LIB ++++++++++++++++++++++++++++++++//
    if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        Log("Unable to init SDL_image: %s", IMG_GetError());
        return false;
    }
//+++++++++++++++++ END PNG LIB +++++++++++++++++++++++++++++++++++++++++//

//+++++++++++++++++ SETANDO ICONE DO APP ++++++++++++++++++++++++++++++++//    
    SDL_Surface* gScreenSurface = SDL_GetWindowSurface(Window);
    SDL_Surface* ggOptimizedSurface = NULL;
    SDL_Surface* ggLoadedSurface = IMG_Load("images/balls/player.png");

    if(ggLoadedSurface == NULL){
        cout << "Erro ao carregar imagem " << endl;
    }
    else
    {
        ggOptimizedSurface = SDL_ConvertSurface( ggLoadedSurface, gScreenSurface->format, 0);
        if(ggOptimizedSurface == NULL)
        {
            cout <<"Erro ao converter imagem." << endl;
        }
    }
    SDL_FreeSurface(gScreenSurface);
    SDL_FreeSurface(ggLoadedSurface);

    SDL_SetWindowIcon(Window, ggOptimizedSurface);
    SDL_FreeSurface(ggOptimizedSurface);
//++++++++++++++ END ICONE APP +++++++++++++++++++++++++++++++++++++++++//

//++++++++++++++ LOADING IMG'S +++++++++++++++++++++++++++++++++++++++++//
    TextureBank[IMG_INITIALSCREEN] = load_PNG("images/background/initialscreen.png");
    TextureBank[IMG_BACKGROUND] = load_PNG("images/background/background.png");
    
    TextureBank[IMG_STARTGAME] = load_PNG("images/menu/startgame.png");
    TextureBank[IMG_GAMEOVER] = load_PNG("images/menu/gameover.png");

    TextureBank[IMG_0] = load_PNG("images/numeros/0.png");
    TextureBank[IMG_1] = load_PNG("images/numeros/1.png");
    TextureBank[IMG_2] = load_PNG("images/numeros/2.png");
    TextureBank[IMG_3] = load_PNG("images/numeros/3.png");
    TextureBank[IMG_4] = load_PNG("images/numeros/4.png");
    TextureBank[IMG_5] = load_PNG("images/numeros/5.png");
    TextureBank[IMG_6] = load_PNG("images/numeros/6.png");
    TextureBank[IMG_7] = load_PNG("images/numeros/7.png");
    TextureBank[IMG_8] = load_PNG("images/numeros/8.png");
    TextureBank[IMG_9] = load_PNG("images/numeros/9.png");

    TextureBank[IMG_USERLIFE] = load_PNG("images/icons/user_life.png");
    TextureBank[IMG_PLAY] = load_PNG("images/icons/play.png");
    TextureBank[IMG_PAUSE] = load_PNG("images/icons/pause.png");
    TextureBank[IMG_PLAYAGAIN] = load_PNG("images/icons/play_again.png");
    TextureBank[IMG_SOUNDON] = load_PNG("images/icons/sound.png");
    TextureBank[IMG_SOUNDOFF] = load_PNG("images/icons/sound_off.png");

    TextureBank[IMG_PLAYER] = load_PNG("images/balls/player.png");
    TextureBank[IMG_POINTER] = load_PNG("images/balls/pointer.png");
    TextureBank[IMG_MURDERER] = load_PNG("images/balls/murderer.png");
    TextureBank[IMG_SAVER] = load_PNG("images/balls/saver.png");
//++++++++++++++ END LOADING ++++++++++++++++++++++++++++++++++++++++++//

//++++++++++++++ SETING VAR'S +++++++++++++++++++++++++++++++++++++++++//
    Running = true;
    screen = 0;

    playerRect.w = 45;//Mouse Width
    playerRect.h = 45;//Mouse Height
//++++++++++++++ END VAR'S +++++++++++++++++++++++++++++++++++++++++++//
    return true;
}