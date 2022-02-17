#include "../../headers/Waves/Wave.h"

Wave::Wave(Loader& loader, std::vector<Enemy*>& enemies, std::vector<Bullet*>& bullets) : enemies(enemies), bullets(bullets) {

}

Wave::~Wave() {

}

bool Wave::endWave() {
    return enemies.empty();
}
