#include "SDL.h"
#include "RenderManager.h"
#include "ResourceManager.h"
#include "Game.h"
#include "Sprite.h"
#include "Transform.h"
#include "Image.h"

#undef main

// ResourceManager 

struct ResourceImpl
{
	ResourceImpl(SDL_Renderer* renderer) : renderer(renderer) {};
	std::vector<std::pair<std::string, SDL_Texture*>> textures;
	SDL_Renderer* renderer;
	SDL_Texture* GetTexture(unsigned int id)
	{
		if (id < textures.size())
			return textures[id].second;
		else
			return nullptr;
	}
};

bool ResourceManager::LoadImageFromFile(Image& image, const std::string &filePath)
{
	auto it = impl.textures.begin();
	unsigned int index = 0;
	while (it != impl.textures.end())
	{
		if ((*it).first == filePath)
		{
			image.m_id = index;
			return true;
		}
		it++;
		index++;
	}
	SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
	if (surface != nullptr)
	{
		SDL_Texture* texture = SDL_CreateTextureFromSurface(impl.renderer, surface);
		if (texture != nullptr)
		{
			impl.textures.push_back(std::pair<std::string, SDL_Texture*>(filePath, texture));
			image.m_id = static_cast<unsigned int>(impl.textures.size() - 1);
			image.m_width = surface->w;
			image.m_height = surface->h;
			return true;
		}
		else
		{
			const char* error = SDL_GetError();
			return false;
		}
	}
	else
	{
		const char* error = SDL_GetError();
		return false;
	}
	return false;
};

// RenderManager

struct RenderImpl
{
	SDL_Renderer* renderer;

};

void RenderManager::Render(const Sprite& sprite, const Transform& trans)
{
	spriteEntries.push_back({ sprite, trans });
}

void RenderManager::Render(const Rectangle& rect, const Color& color, const Transform& trans)
{
	rectEntries.push_back({ rect, color, trans });
}

void RenderManager::Clear()
{
	spriteEntries.clear();
	rectEntries.clear();
}

KeyCode TranslateKeyCode(SDL_Keycode code)
{
	switch (code)
	{
	case SDLK_ESCAPE: return KeyCode::ESCAPE; break;
	case SDLK_SPACE: return KeyCode::SPACE; break;
	case SDLK_RETURN: return KeyCode::ENTER; break;
	case SDLK_RETURN2: return KeyCode::ENTER; break;
	case SDLK_a: return KeyCode::A; break;
	case SDLK_b: return KeyCode::B; break;
	case SDLK_c: return KeyCode::C; break;
	case SDLK_d: return KeyCode::D; break;
	case SDLK_e: return KeyCode::E; break;
	case SDLK_f: return KeyCode::F; break;
	case SDLK_g: return KeyCode::G; break;
	case SDLK_h: return KeyCode::H; break;
	case SDLK_i: return KeyCode::I; break;
	case SDLK_j: return KeyCode::J; break;
	case SDLK_k: return KeyCode::K; break;
	case SDLK_l: return KeyCode::L; break;
	case SDLK_m: return KeyCode::M; break;
	case SDLK_n: return KeyCode::N; break;
	case SDLK_o: return KeyCode::O; break;
	case SDLK_p: return KeyCode::P; break;
	case SDLK_q: return KeyCode::Q; break;
	case SDLK_r: return KeyCode::R; break;
	case SDLK_s: return KeyCode::S; break;
	case SDLK_t: return KeyCode::T; break;
	case SDLK_u: return KeyCode::U; break;
	case SDLK_v: return KeyCode::V; break;
	case SDLK_w: return KeyCode::W; break;
	case SDLK_x: return KeyCode::X; break;
	case SDLK_y: return KeyCode::Y; break;
	case SDLK_z: return KeyCode::Z; break;
	case SDLK_LEFT: return KeyCode::LEFT_ARROW; break;
	case SDLK_RIGHT: return KeyCode::RIGHT_ARROW; break;
	case SDLK_UP: return KeyCode::UP_ARROW; break;
	case SDLK_DOWN: return KeyCode::DOWN_ARROW; break;
	default: return KeyCode::INVALID; break;
	}
}

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Base", 0, 0, 0, 0, SDL_WindowFlags::SDL_WINDOW_RESIZABLE);
	if (window == nullptr)
	{
		const char* error = SDL_GetError();
		return 0;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		const char* error = SDL_GetError();
		return 0;
	}
	bool running = true;
	
	RenderManager renderManager;
	ResourceImpl resourceImpl(renderer);
	ResourceManager resourceManager(resourceImpl);
	Game game(resourceManager);

	unsigned int width = 500;
	unsigned height = 500;
	std::string title = "";
	game.Enter(width, height, title);
	SDL_SetWindowSize(window, width, height);
	SDL_SetWindowTitle(window, title.c_str());
	SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	
	float dt = 1.0f / 60.0f;
	while (running)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT: running = false; break;
			case SDL_KEYDOWN: game.OnKeyDown(TranslateKeyCode(e.key.keysym.sym)); break;
			case SDL_KEYUP: game.OnKeyUp(TranslateKeyCode(e.key.keysym.sym)); break;
			}
		}

		game.Update();
		game.Render(renderManager);

		SDL_SetRenderDrawColor(renderer,0,0,0,0);
		SDL_RenderClear(renderer);
		for (auto &&entry : renderManager.spriteEntries)
		{
			if (entry.sprite.m_image != nullptr)
			{
				SDL_Rect src{ entry.sprite.source.m_x, entry.sprite.source.m_y, entry.sprite.source.m_w, entry.sprite.source.m_h };
				SDL_Rect dst{ static_cast<int>(entry.trans.m_position.x),
							  static_cast<int>(entry.trans.m_position.y),
							  static_cast<int>(entry.sprite.m_image->m_width),
							  static_cast<int>(entry.sprite.m_image->m_height) };
				SDL_RenderCopy(renderer, resourceImpl.GetTexture(entry.sprite.m_image->m_id), &src, &dst);
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, entry.sprite.color.m_r, entry.sprite.color.m_g, entry.sprite.color.m_b, entry.sprite.color.m_a);
				SDL_Rect rect{ static_cast<int>(entry.trans.m_position.x),
							   static_cast<int>(entry.trans.m_position.y),
							   entry.sprite.source.m_w,
							   entry.sprite.source.m_h };
				SDL_RenderDrawRect(renderer, &rect);
			}
		}
		for (auto&& entry : renderManager.rectEntries)
		{
			SDL_SetRenderDrawColor(renderer, entry.color.m_r, entry.color.m_g, entry.color.m_b, entry.color.m_a);
			SDL_Rect rect{ static_cast<int>(entry.trans.m_position.x),
						   static_cast<int>(entry.trans.m_position.y),
						   entry.rect.m_w,
						   entry.rect.m_h };
			//SDL_RenderDrawRect(renderer, &rect);	// <- If you want to draw the "outline" of the rectangle.
			SDL_RenderFillRect(renderer, &rect);  // <- If you want to draw a "filled" rectangle. 
		}
		SDL_RenderPresent(renderer);
		renderManager.Clear();
		SDL_Delay(1000 / 20); //<- "Framerate".
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}
