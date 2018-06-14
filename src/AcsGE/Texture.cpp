
#include "Texture.h"
#include "Renderer.h"
#include <SDL2/SDL_image.h>

namespace AcsGameEngine {

    Texture::Texture(SDL_Texture *texture) : m_texturePtr(texture, SDL_DestroyTexture) {
    }    

    SDL_Texture * Texture::getRawPointer() const
    {
		return m_texturePtr.get();
    }

} // namespace AcsGameEngine
