#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);

        // Si la clave no está en la caché
        if (it == cache.end()) {
            return -1;
        }

        // Mover la clave al frente de la lista (indicando uso más reciente)
        lista.splice(lista.begin(), lista, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        // Si la clave ya está en la caché
        if (it != cache.end()) {
            // Actualizar el valor y mover al frente de la lista
            it->second->second = value;
            lista.splice(lista.begin(), lista, it->second);
        } else {
            // Si la caché está llena, eliminar el elemento menos recientemente usado
            if (lista.size() == capacity) {
                int keyToRemove = lista.back().first;
                lista.pop_back();
                cache.erase(keyToRemove);
            }

            // Insertar el nuevo elemento al frente de la lista y en el mapa
            lista.push_front({key, value});
            cache[key] = lista.begin();
        }
    }

private:
    int capacity;
    std::list<std::pair<int, int>> lista;                      // Lista para mantener el orden de uso
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache; // Mapa para acceso rápido por clave
};

int main() {
    // Ejemplo de uso
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1) << std::endl; // Debería imprimir 1
    cache.put(3, 3); // Reemplaza el 2, ya que 2 fue el menos recientemente usado
    std::cout << cache.get(2) << std::endl; // Debería imprimir -1 (no encontrado)
    cache.put(4, 4); // Reemplaza el 1, ya que 1 fue el menos recientemente usado
    std::cout << cache.get(1) << std::endl; // Debería imprimir -1 (no encontrado)
    std::cout << cache.get(3) << std::endl; // Debería imprimir 3
    std::cout << cache.get(4) << std::endl; // Debería imprimir 4

    return 0;
}
