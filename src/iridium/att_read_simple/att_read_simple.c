#include <px4_config.h>
#include <px4_tasks.h>
#include <px4_posix.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>

#include <uORB/uORB.h>
#include <uORB/topics/vehicle_attitude.h>

__EXPORT int att_read_simple_main(int argc, char *argv[]);

int att_read_simple_main(int argc, char *argv[]) {
    PX4_INFO("Hello Sky!");
    
    int att = orb_subscribe(ORB_ID(vehicle_attitude));
    orb_set_interval(att, 1000);

    px4_pollfd_struct_t fds[] = {
            { .fd = att,   .events = POLLIN },
    };

    int poll_ret = px4_poll(fds, 1, 1000);

    if (poll_ret == 0) {
            PX4_ERR("[px4_simple_app] Got no data within a second");
    } else if (poll_ret < 0) {
            PX4_ERR("[px4_simple_app] ERROR return value from poll(): %d", poll_ret);

    } else {
            if (fds[0].revents & POLLIN) {
                    struct vehicle_attitude_s raw;
                    orb_copy(ORB_ID(vehicle_attitude), att, &raw);
                    PX4_INFO("[iridium_att_read_simple] Yaw:\t%8.4f", (double)raw.yaw);
            }
    }
    
    return 0;
}

