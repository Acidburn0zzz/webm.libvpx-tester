#include <string>

#define DELETE_IVF 1
#define KEEP_IVF 0

/////Tests
int run_multiple_tests(int argc,
                              const char *argv[],
                              std::string WorkingDir,
                              int NumberofTests,
                              int DeleteIVFFiles);
int test_allow_drop_frames(int argc,
                                  const char *const *argv,
                                  const std::string &WorkingDir,
                                  std::string FilesAr[],
                                  int TestType,
                                  int DeleteIVF);
int test_allow_lag(int argc,
                          const char *const *argv,
                          const std::string &WorkingDir,
                          std::string FilesAr[],
                          int TestType,
                          int DeleteIVF);
int test_allow_spatial_resampling(int argc,
                                         const char *const *argv,
                                         const std::string &WorkingDir,
                                         std::string FilesAr[],
                                         int TestType,
                                         int DeleteIVF);
int test_arnr(int argc,
                     const char *const *argv,
                     const std::string &WorkingDir,
                     std::string FilesAr[],
                     int TestType,
                     int DeleteIVF);
int test_auto_key_frame(int argc,
                               const char *const *argv,
                               const std::string &WorkingDir,
                               std::string FilesAr[],
                               int TestType,
                               int DeleteIVF);
int test_buffer_level(int argc,
                             const char *const *argv,
                             const std::string &WorkingDir,
                             std::string FilesAr[],
                             int TestType,
                             int DeleteIVF);
int test_change_cpu_dec(int argc,
                               const char *const *argv,
                               const std::string &WorkingDir,
                               std::string FilesAr[],
                               int TestType,
                               int DeleteIVF);
int test_change_cpu_enc(int argc,
                               const char *const *argv,
                               const std::string &WorkingDir,
                               std::string FilesAr[],
                               int TestType,
                               int DeleteIVF);
int test_constrained_quality(int argc,
                                    const char *const *argv,
                                    const std::string &WorkingDir,
                                    std::string FilesAr[],
                                    int TestType,
                                    int DeleteIVF);
int test_copy_set_reference(int argc,
                                   const char *const *argv,
                                   const std::string &WorkingDir,
                                   std::string FilesAr[],
                                   int TestType,
                                   int DeleteIVF);
int test_drop_frame_watermark(int argc,
                                     const char *const *argv,
                                     const std::string &WorkingDir,
                                     std::string FilesAr[],
                                     int TestType,
                                     int DeleteIVF);
int test_data_rate(int argc,
                          const char *const *argv,
                          const std::string &WorkingDir,
                          std::string FilesAr[],
                          int TestType,
                          int DeleteIVF);
int test_debug_matches_release(int argc,
                                      const char *const *argv,
                                      const std::string &WorkingDir,
                                      std::string FilesAr[],
                                      int TestType,
                                      int DeleteIVF);
int test_encoder_break_out(int argc,
                                  const char *const *argv,
                                  const std::string &WorkingDir,
                                  std::string FilesAr[],
                                  int TestType,
                                  int DeleteIVF);
int test_error_concealment(int argc,
                                  const char *const *argv,
                                  const std::string &WorkingDir,
                                  std::string FilesAr[],
                                  int TestType,
                                  int DeleteIVF);
int test_error_resolution(int argc,
                                 const char *const *argv,
                                 const std::string &WorkingDir,
                                 std::string FilesAr[],
                                 int TestType,
                                 int DeleteIVF);
int test_extra_file(int argc,
                           const char *const *argv,
                           const std::string &WorkingDir,
                           std::string FilesAr[],
                           int TestType,
                           int DeleteIVF);
int test_fixed_quantizer(int argc,
                                const char *const *argv,
                                const std::string &WorkingDir,
                                std::string FilesAr[],
                                int TestType,
                                int DeleteIVF);
int test_force_key_frame(int argc,
                                const char *const *argv,
                                const std::string &WorkingDir,
                                std::string FilesAr[],
                                int TestType,
                                int DeleteIVF);
int test_frame_size(int argc,
                           const char *const *argv,
                           const std::string &WorkingDir,
                           std::string FilesAr[],
                           int TestType,
                           int DeleteIVF);
int test_good_vs_best(int argc,
                             const char *const *argv,
                             const std::string &WorkingDir,
                             std::string FilesAr[],
                             int TestType,
                             int DeleteIVF);
int test_lag_in_frames(int argc,
                              const char *const *argv,
                              const std::string &WorkingDir,
                              std::string FilesAr[],
                              int TestType,
                              int DeleteIVF);
int test_max_quantizer(int argc,
                              const char *const *argv,
                              const std::string &WorkingDir,
                              std::string FilesAr[],
                              int TestType,
                              int DeleteIVF);
int test_mem_leak(int argc,
                         const char *const *argv,
                         const std::string &WorkingDir,
                         std::string FilesAr[],
                         int TestType,
                         int DeleteIVF);
int test_mem_leak2(int argc,
                          const char *const *argv,
                          const std::string &WorkingDir,
                          std::string FilesAr[],
                          int TestType,
                          int DeleteIVF);
int test_min_quantizer(int argc,
                              const char *const *argv,
                              const std::string &WorkingDir,
                              std::string FilesAr[],
                              int TestType,
                              int DeleteIVF);
int test_multiple_resolution_encode(int argc,
                                           const char *const *argv,
                                           const std::string &WorkingDir,
                                           std::string FilesAr[],
                                           int TestType,
                                           int DeleteIVF);
int test_multithreaded_dec(int argc,
                                  const char *const *argv,
                                  const std::string &WorkingDir,
                                  std::string FilesAr[],
                                  int TestType,
                                  int DeleteIVF);
int test_multithreaded_enc(int argc,
                                  const char *const *argv,
                                  const std::string &WorkingDir,
                                  std::string FilesAr[],
                                  int TestType,
                                  int DeleteIVF);
int test_new_vs_old_psnr(int argc,
                                const char *const *argv,
                                const std::string &WorkingDir,
                                std::string FilesAr[],
                                int TestType,
                                int DeleteIVF);
int test_new_vs_old_temp_scale(int argc,
                                      const char *const *argv,
                                      const std::string &WorkingDir,
                                      std::string FilesAr[],
                                      int TestType,
                                      int DeleteIVF);
int test_new_vs_old_enc_cpu_tick(int argc,
                                        const char *const *argv,
                                        const std::string &WorkingDir,
                                        std::string FilesAr[],
                                        int TestType,
                                        int DeleteIVF);
int test_noise_sensitivity(int argc,
                                  const char *const *argv,
                                  const std::string &WorkingDir,
                                  std::string FilesAr[],
                                  int TestType,
                                  int DeleteIVF);
int test_one_pass_vs_two_pass(int argc,
                                     const char *const *argv,
                                     const std::string &WorkingDir,
                                     std::string FilesAr[],
                                     int TestType,
                                     int DeleteIVF);
int test_play_alternate(int argc,
                               const char *const *argv,
                               const std::string &WorkingDir,
                               std::string FilesAr[],
                               int TestType,
                               int DeleteIVF);
int test_post_processor(int argc,
                               const char *const *argv,
                               const std::string &WorkingDir,
                               std::string FilesAr[],
                               int TestType,
                               int DeleteIVF);
int test_post_processor_mfqe(int argc,
                                   const char *const *argv,
                                   const std::string &WorkingDir,
                                   std::string FilesAr[],
                                   int TestType,
                                   int DeleteIVF);
int test_reconstruct_buffer(int argc,
                                   const char *const *argv,
                                   const std::string &WorkingDir,
                                   std::string FilesAr[],
                                   int TestType,
                                   int DeleteIVF);
int test_resample_down_watermark(int argc,
                                        const char *const *argv,
                                        const std::string &WorkingDir,
                                        std::string FilesAr[],
                                        int TestType,
                                        int DeleteIVF);
int test_speed(int argc,
                      const char *const *argv,
                      const std::string &WorkingDir,
                      std::string FilesAr[],
                      int TestType,
                      int DeleteIVF);
int test_temporal_scalability(int argc,
                                     const char *const *argv,
                                     const std::string &WorkingDir,
                                     std::string FilesAr[],
                                     int TestType,
                                     int DeleteIVF);
int test_test_vector(int argc,
                            const char *const *argv,
                            const std::string &WorkingDir,
                            std::string FilesAr[],
                            int TestType,
                            int DeleteIVF);
int test_thirtytwo_vs_sixtyfour(int argc,
                                       const char *const *argv,
                                       const std::string &WorkingDir,
                                       std::string FilesAr[],
                                       int TestType,
                                       int DeleteIVF);
int test_two_pass_vs_two_pass_best(int argc,
                                          const char *const *argv,
                                          const std::string &WorkingDir,
                                          std::string FilesAr[],
                                          int TestType,
                                          int DeleteIVF);
int test_undershoot(int argc,
                           const char *const *argv,
                           const std::string &WorkingDir,
                           std::string FilesAr[],
                           int TestType,
                           int DeleteIVF);
int test_version(int argc,
                        const char *const *argv,
                        const std::string &WorkingDir,
                        std::string FilesAr[],
                        int TestType,
                        int DeleteIVF);
int test_vpx_matches_int(int argc,
                                const char *const *argv,
                                const std::string &WorkingDir,
                                std::string FilesAr[],
                                int TestType,
                                int DeleteIVF);
int test_win_lin_mac_match(int argc,
                                  const char *const *argv,
                                  const std::string &WorkingDir,
                                  std::string FilesAr[],
                                  int TestType,
                                  int DeleteIVF);

//Tools
int tool_rand_comp(int argc,
                          const char *const *argv,
                          const std::string &WorkingDir,
                          std::string FilesAr[],
                          int TestType);
int tool_graph_psnr(int argc,
                           const char *const *argv,
                           const std::string &WorkingDir,
                           std::string FilesAr[],
                           int TestType);
