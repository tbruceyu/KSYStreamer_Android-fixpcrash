extern "C" {
#include <xhook.h>
#include <pthread.h>
#include <jni.h>

static int my_pthread_mutex_destroy(pthread_mutex_t *mutex)
{

    if ((*((int32_t*)mutex) & 0x0000ffff) != 0x0000ffff) {
        return pthread_mutex_destroy(mutex);
    }
    return 0;
}

void Java_com_tby_fixcrash_FixAndroidPCrash_fixAndroidPCrash(
        JNIEnv *env, jclass clazz) {
    xhook_register(".*\\ksylive.so$", "pthread_mutex_destroy", (void *) my_pthread_mutex_destroy, NULL);
    xhook_refresh(1);
}

}
