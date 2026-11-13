#include "include/downloader.h"
#include <curl/curl.h>
#include <curl/easy.h>
#include <stdio.h>

int yap_download(const char *url, const char *path) {
    if (!url || !path) return -1;

    FILE *file = fopen(path, "wb");
    if (!file) return -1;

    CURL *curl = curl_easy_init();
    if (!curl) {
        fclose(file);
        remove(path);
        return -1;
    }

    CURLcode result = curl_easy_setopt(curl, CURLOPT_URL, url);

    if (result == CURLE_OK)
        result = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    if (result == CURLE_OK)
        result = curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

    if (result == CURLE_OK)
        result = curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

    if (result == CURLE_OK)
        result = curl_easy_perform(curl);

    if (result != CURLE_OK)
        fprintf(stderr, "Download failed: %s\n",
            curl_easy_strerror(result));

    int success = (result == CURLE_OK);

    if (fclose(file) != 0)
        success = 0;

    curl_easy_cleanup(curl);

    if (!success)
        remove(path);

    return success ? 0 : -1;
}
