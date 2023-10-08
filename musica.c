/**
 * @file playMp3.c
 * @brief Reproduzindo um arquivo mp3 no Windows usando VLC
 * @date 2023-10-08
 * 
 * Para compilar use:
 * gcc playMp3.c -o playMp3 -I"C:\Program Files\VideoLAN\VLC\SDK\include" -L"C:\Program Files\VideoLAN\VLC\SDK\lib" -lvlc
 */

#include <stdio.h>
#include <stdlib.h>
#include <vlc/vlc.h>
#include <unistd.h>

int main(int argc, char **argv) {
    libvlc_instance_t *instance;
    libvlc_media_player_t *mediaPlayer;
    libvlc_media_t *media;

    // Inicializa a engine do VLC
    instance = libvlc_new(0, NULL);

    // Cria uma nova media de reprodução
    media = libvlc_media_new_path(instance, "musica.mp3");

    // Cria um media player usando a media
    mediaPlayer = libvlc_media_player_new_from_media(media);

    // Libera a media. Não é mais necessária
    libvlc_media_release(media);

    // Define a janela de visualização como NULL para reprodução de áudio somente
    libvlc_media_player_set_hwnd(mediaPlayer, NULL);

    // Reproduz a música do media player criado
    libvlc_media_player_play(mediaPlayer);

    // Aguarda a reprodução por 10 segundos (ou o tempo desejado)
    Sleep(10000);

    // Para a reprodução da música
    libvlc_media_player_stop(mediaPlayer);

    // Libera o media player
    libvlc_media_player_release(mediaPlayer);

    // Descarrega a engine do VLC
    libvlc_release(instance);

    return 0;
}