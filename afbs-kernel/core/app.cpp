#include "afbs.h"
#include "app.h"

int TASK_1_PERIOD = 1000;
int TASK_2_PERIOD = 1000;
int TASK_3_PERIOD = 1000;

int TASK_1_IDX = 0;
int TASK_2_IDX = 1;
int TASK_3_IDX = 2;

/* task configurations */
int task_config[TASK_NUMBERS][5] = {
{0,   42,   157, 0, 0},
{1,   10,   215, 0, 0},
{2,   53,   499, 0, 0},
{3,   87,   777, 0, 0},
{4,   48,   801, 0, 0},
{5,  100,  1000, 0, 0},
};

void app_init(void) {
    /* read parameters */
    //TASK_1_PERIOD = afbs_get_param(0) / KERNEL_TICK_TIME;
    //TASK_2_PERIOD = afbs_get_param(1) / KERNEL_TICK_TIME;
    //TASK_3_PERIOD = afbs_get_param(2) / KERNEL_TICK_TIME;

    /* initialize task list */
    for (int i = 0; i < TASK_NUMBERS; i++) {
        class Task ti(task_config[i][0], task_config[i][1], task_config[i][2],
                    task_config[i][3], task_config[i][4]);
        afbs_create_task(ti, NULL, NULL, NULL);
    }

    /* override some tasks for control tasks */
    class Task tau1(TASK_1_IDX, 20, TASK_1_PERIOD, 0, 0);
    class Task tau2(TASK_2_IDX, 20, TASK_2_PERIOD, 0, 0);
    class Task tau3(TASK_3_IDX, 20, TASK_3_PERIOD, 0, 0);
    
    afbs_create_task(tau1, NULL, task_1_start_hook, task_1_finish_hook);
    afbs_create_task(tau2, NULL, task_2_start_hook, task_2_finish_hook);
    afbs_create_task(tau3, NULL, task_3_start_hook, task_3_finish_hook);

    return;
}


/*-- control tasks -----------------------------------------------------------*/
double ref[3];
double x[3];
double error[3];

void task_1_start_hook(void) {
    idx = 0;
    
    // sample inputs
    ref[idx] = afbs_state_ref_load(idx);
    x[idx] = afbs_state_in_load(idx);
    
    // calculate error
    error[idx] = ref[idx] - x[idx];
    
    return;
}

void task_1_finish_hook(void) {
    idx = 0;
    
    /* Calculate Outputs */
    double u = 4210;

    
    
    /* Send output to Simulink */
    afbs_state_out_set(0, u);

    
/*
    t_refer = ref[0];
    t_error = ref[0] - y[0];
    error[0] = abs(ref[0] - y[0]);
    u[0] = 75 * (t_error) + 80 * error_s[0] + 0.036 * error_p[0] / (TCB[0].T_ / 10000.0);
    error_s[0] += t_error * (TCB[0].T_ / 10000.0);
    error_p[0] = t_error;
    u[0] = 1;
*/


    return;
}

void task_2_start_hook(void) {
    /* sample inputs */
    ref = afbs_state_ref_load(0);
    x2 = afbs_state_in_load(1);
    
    return;
}

void task_2_finish_hook(void) {
    /* Calculate Outputs */
    double u = 10;

    /* Send output to Simulink */
    afbs_state_out_set(1, u);
    return;
}

void task_3_start_hook(void) {
    /* sample inputs */
    ref = afbs_state_ref_load(0);
    x3 = afbs_state_in_load(2);
    
    return;
}

void task_3_finish_hook(void) {
    /* Calculate Outputs */
    double u = 20;

    /* Send output to Simulink */
    afbs_state_out_set(2, u);
    return;
}
