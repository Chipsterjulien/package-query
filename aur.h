#ifndef _AUR_H
#define _AUR_H
#include <alpm_list.h>

#define AUR_BASE_URL "http://aur.archlinux.org"


/*
 * AUR package
 */
typedef struct _aurpkg_t
{
	unsigned int id;
	char *name;
	char *version;
	unsigned int category;
	char *desc;
	unsigned int location;
	char *url;
	char *urlpath;
	char *license;
	unsigned int votes;
	unsigned short outofdate;
} aurpkg_t;

#define AUR_ID_LEN 	20

/*
 * JSON parse packages
 */
typedef struct _package_json_t
{
	aurpkg_t *pkg;
	char current_key[AUR_ID_LEN];
} package_json_t;

aurpkg_t *aur_pkg_new ();
aurpkg_t *aur_pkg_free (aurpkg_t *pkg);
aurpkg_t *aur_pkg_dup (const aurpkg_t *pkg);
int aur_pkg_cmp (const aurpkg_t *pkg1, const aurpkg_t *pkg2);

unsigned int aur_pkg_get_id (const aurpkg_t * pkg);
const char * aur_pkg_get_name (const aurpkg_t * pkg);
const char * aur_pkg_get_version (const aurpkg_t * pkg);
const char * aur_pkg_get_desc (const aurpkg_t * pkg);
const char * aur_pkg_get_url (const aurpkg_t * pkg);
const char * aur_pkg_get_urlpath (const aurpkg_t * pkg);
const char * aur_pkg_get_license (const aurpkg_t * pkg);
unsigned int aur_pkg_get_votes (const aurpkg_t * pkg);
unsigned short aur_pkg_get_outofdate (const aurpkg_t * pkg);



/*
 * AUR search function
 * Returns number of packages found
 * This function call print_package()
 */
int aur_search (alpm_list_t *targets);
int aur_info (alpm_list_t *targets);
/* aur_info_none print infomation even if package is not found */
int aur_info_none (alpm_list_t *targets);

/*
 * aur_get_str() get info for package
 * str returned should not be passed to free
 */
const char *aur_get_str (void *p, unsigned char c);

#endif
