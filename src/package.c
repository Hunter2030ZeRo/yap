#include <stdlib.h>
#include "include/package.h"

void yap_package_free(yap_package *package) {
    if (!package) return;

    free(package->name);
    free(package->version);
    free(package->url);
    free(package->sha256);
}
