#ifdef YAP_PACKAGE_H
#define YAP_PACKAGE_H

typedef struct {
    char *name;
    char *version;
    char *url;
    char *sha256;
} yap_package;

void yap_package_free(yap_package *package);

#endif
