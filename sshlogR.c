#include <systemd/sd-journal.h>
#include <stdio.h>
#include <string.h>
#include <string.h>


int grep(){

}


int main(void) {
      sd_journal *a = NULL;
      int ret;

      ret = sd_journal_open(&a, SD_JOURNAL_SYSTEM);
      if (ret < 0) {
            printf("FAILED TO OPEN THE JOURNAL: %s\n", strerror(-ret));
            return 1;
      }

      ret = sd_journal_add_match(a, "_SYSTEMD_UNIT=ssh.service", 0);
      if (ret < 0) {
            printf("FAILED TO ADD MATCH: %s\n", strerror(-ret));
            return 1;
      }

      ret = sd_journal_seek_tail(a);
      if (ret < 0) {
            printf("FAILED TO SEEK TAIL: %s\n", strerror(-ret));
            return 1;
      }

      ret = sd_journal_previous(a);
      if (ret < 0) {
            printf("FAILED TO STEP BACK: %s\n", strerror(-ret));
            return 1;
      }

      printf("Listening for ssh.service journal entries...\n");

      for (;;) {
            ret = sd_journal_next(a);
            if (ret < 0) {
                  printf("FAILED TO READ NEXT ENTRY: %s\n", strerror(-ret));
                  break;
            }

            if (ret == 0) {
                  ret = sd_journal_wait(a, (uint64_t) -1);
                  if (ret < 0) {
                  printf("FAILED TO WAIT: %s\n", strerror(-ret));
                  break;
                  }
                  continue;
            }

            const void *data;
            size_t length;

            ret = sd_journal_get_data(a, "MESSAGE", &data, &length);
            if (ret > 0 && strstr((const char *) data, "Accepted password") != NULL) {
                  
            }

      }

      sd_journal_close(a);
      return 0;
}
