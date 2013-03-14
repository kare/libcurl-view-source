#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
    return fwrite(buffer, size, nmemb, stdout);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: view-source hostname\n");
        return EXIT_FAILURE;
    }

    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "error: %s\n", curl_easy_strerror(res));
    }
    curl_easy_cleanup(curl);
}
