#include "vpxt_test_declarations.h"

int test_mem_leak(int argc,
                  const char *const *argv,
                  const std::string &WorkingDir,
                  std::string FilesAr[],
                  int TestType,
                  int DeleteIVF)
{
    //Needs Debug.exe
    char *MyDir = "test_mem_leak";
    int inputCheck = vpxt_check_arg_input(argv[1], argc);

    if (inputCheck < 0)
        return vpxt_test_help(argv[1], 0);

    std::string input = argv[2];
    int Mode = atoi(argv[3]);
    int BitRate = atoi(argv[4]);
    char MemLeakExe[255];
    std::string MemLeakExeStr = argv[5];
    snprintf(MemLeakExe, 255, "%s", MemLeakExeStr.c_str());
    std::string EncForm = argv[6];
    std::string DecForm = argv[7];

    ////////////Formatting Test Specific Directory////////////
    std::string CurTestDirStr = "";
    char MainTestDirChar[255] = "";
    std::string FileIndexStr = "";
    char FileIndexOutputChar[255] = "";

    if (initialize_test_directory(argc, argv, TestType, WorkingDir, MyDir,
        CurTestDirStr, FileIndexStr, MainTestDirChar, FileIndexOutputChar, FilesAr) == 11)
        return 11;

    std::string ExeMemLeakStr;
    vpxt_folder_name(argv[0], &ExeMemLeakStr);

    /////////////////////////////////////////////////
    std::string MemLeakCheckIVFDECStr = CurTestDirStr;
    MemLeakCheckIVFDECStr.append(slashCharStr());
    MemLeakCheckIVFDECStr.append(MyDir);
    MemLeakCheckIVFDECStr.append("_decompression");
    vpxt_dec_format_append(MemLeakCheckIVFDECStr, DecForm);
    /////////////////////////////////////////////////

    std::string MemLeakCheckIVFStr = CurTestDirStr;
    MemLeakCheckIVFStr.append(slashCharStr());
    MemLeakCheckIVFStr.append(MyDir);
    MemLeakCheckIVFStr.append("_compression");
    vpxt_enc_format_append(MemLeakCheckIVFStr, EncForm);

    std::string EncMemLeakCheckTxtStr = CurTestDirStr;
    EncMemLeakCheckTxtStr.append(slashCharStr());
    EncMemLeakCheckTxtStr.append(MyDir);
    EncMemLeakCheckTxtStr.append("_compression_memory_summary.txt");

    std::string DecMemLeakCheckTxtStr = CurTestDirStr;
    DecMemLeakCheckTxtStr.append(slashCharStr());
    DecMemLeakCheckTxtStr.append(MyDir);
    DecMemLeakCheckTxtStr.append("_decompression_memory_summary.txt");

    std::string MemLeakCheckParFileStr = CurTestDirStr;
    MemLeakCheckParFileStr.append(slashCharStr());
    MemLeakCheckParFileStr.append(MyDir);
    MemLeakCheckParFileStr.append("_compression_parameter_file.txt");

    std::string ProgramEncMemLeakCheckStr = "";
    std::string ProgramDecMemLeakCheckStr = "";

#if defined(_WIN32)
    {
        //compression
        ProgramEncMemLeakCheckStr = "\"\"";
        ProgramEncMemLeakCheckStr.append(ExeMemLeakStr.c_str());
        ProgramEncMemLeakCheckStr.append(MemLeakExe);
        ProgramEncMemLeakCheckStr.append("\" memcompress \"");
        ProgramEncMemLeakCheckStr.append(input.c_str());
        ProgramEncMemLeakCheckStr.append("\" \"");
        ProgramEncMemLeakCheckStr.append(MemLeakCheckIVFStr.c_str());
        ProgramEncMemLeakCheckStr.append("\" 8 \"");
        ProgramEncMemLeakCheckStr.append(MemLeakCheckParFileStr.c_str());
        ProgramEncMemLeakCheckStr.append("\" 0 \"");
        ProgramEncMemLeakCheckStr.append(EncMemLeakCheckTxtStr.c_str());
        ProgramEncMemLeakCheckStr.append("\"\"");
        //decompression
        ProgramDecMemLeakCheckStr = "\"\"";
        ProgramDecMemLeakCheckStr.append(ExeMemLeakStr.c_str());
        ProgramDecMemLeakCheckStr.append(MemLeakExe);
        ProgramDecMemLeakCheckStr.append("\" memdecompress \"");
        ProgramDecMemLeakCheckStr.append(MemLeakCheckIVFStr.c_str());
        ProgramDecMemLeakCheckStr.append("\" \"");
        ProgramDecMemLeakCheckStr.append(MemLeakCheckIVFDECStr.c_str());
        ProgramDecMemLeakCheckStr.append("\" \"");
        ProgramDecMemLeakCheckStr.append(DecMemLeakCheckTxtStr.c_str());
        ProgramDecMemLeakCheckStr.append("\"\"");
    }
#else
    {
        //compression
        ProgramEncMemLeakCheckStr = "\"";
        ProgramEncMemLeakCheckStr.append(ExeMemLeakStr.c_str());
        ProgramEncMemLeakCheckStr.append(MemLeakExe);
        ProgramEncMemLeakCheckStr.append("\" memcompress \"");
        ProgramEncMemLeakCheckStr.append(input.c_str());
        ProgramEncMemLeakCheckStr.append("\" \"");
        ProgramEncMemLeakCheckStr.append(MemLeakCheckIVFStr.c_str());
        ProgramEncMemLeakCheckStr.append("\" 8 \"");
        ProgramEncMemLeakCheckStr.append(MemLeakCheckParFileStr.c_str());
        ProgramEncMemLeakCheckStr.append("\" 0 \"");
        ProgramEncMemLeakCheckStr.append(EncMemLeakCheckTxtStr.c_str());
        ProgramEncMemLeakCheckStr.append("\"");
        //decompression
        ProgramDecMemLeakCheckStr = "\"";
        ProgramDecMemLeakCheckStr.append(ExeMemLeakStr.c_str());
        ProgramDecMemLeakCheckStr.append(MemLeakExe);
        ProgramDecMemLeakCheckStr.append("\" memdecompress \"");
        ProgramDecMemLeakCheckStr.append(MemLeakCheckIVFStr.c_str());
        ProgramDecMemLeakCheckStr.append("\" \"");
        ProgramDecMemLeakCheckStr.append(MemLeakCheckIVFDECStr.c_str());
        ProgramDecMemLeakCheckStr.append("\" \"");
        ProgramDecMemLeakCheckStr.append(DecMemLeakCheckTxtStr.c_str());
        ProgramDecMemLeakCheckStr.append("\"");
    }
#endif

    /////////////OutPutfile////////////
    std::string TextfileString = CurTestDirStr;
    TextfileString.append(slashCharStr());
    TextfileString.append(MyDir);

    if (TestType == COMP_ONLY || TestType == TEST_AND_COMP)
        TextfileString.append(".txt");
    else
        TextfileString.append("_TestOnly.txt");

    FILE *fp;

    if ((fp = freopen(TextfileString.c_str(), "w", stderr)) == NULL)
    {
        tprintf(PRINT_STD, "Cannot open out put file: %s\n",
            TextfileString.c_str());
        exit(1);
    }

    ////////////////////////////////
    //////////////////////////////////////////////////////////

    if (TestType == TEST_AND_COMP)
        print_header_full_test(argc, argv, MainTestDirChar);

    if (TestType == COMP_ONLY)
        print_header_compression_only(argc, argv, MainTestDirChar);

    if (TestType == TEST_ONLY)
        print_header_test_only(argc, argv, CurTestDirStr);

    vpxt_cap_string_print(PRINT_BTH, "%s", MyDir);

    VP8_CONFIG opt;
    vpxt_default_parameters(opt);

    ///////////////////Use Custom Settings///////////////////
    if (inputCheck == 2)
    {
        if (!vpxt_file_exists_check(argv[argc-1]))
        {
            tprintf(PRINT_BTH, "\nInput Settings file %s does not exist\n",
                argv[argc-1]);

            fclose(fp);
            record_test_complete(FileIndexStr, FileIndexOutputChar, TestType);
            return 2;
        }

        opt = vpxt_input_settings(argv[argc-1]);
        BitRate = opt.target_bandwidth;
    }

    /////////////////Make Sure Exe File Exists///////////////
    if (!vpxt_file_exists_check(argv[5]))
    {
        tprintf(PRINT_BTH, "\nInput executable %s does not exist\n", argv[5]);

        fclose(fp);
        record_test_complete(FileIndexStr, FileIndexOutputChar, TestType);
        return 2;
    }

    /////////////////Make Sure ivf File Exists///////////////
    if (!vpxt_file_exists_check(argv[2]))
    {
        tprintf(PRINT_BTH, "\nInput encode file %s does not exist\n", argv[2]);

        fclose(fp);
        record_test_complete(FileIndexStr, FileIndexOutputChar, TestType);
        return 2;
    }

    /////////////////////////////////////////////////////////

    opt.target_bandwidth = BitRate ;

    //Run Test only (Runs Test, Sets up test to be run, or skips compresion of
    //files)
    if (TestType == TEST_ONLY)
    {
        //This test requires no preperation before a Test Only Run
    }
    else
    {
        fclose(fp);

        if ((fp = freopen(TextfileString.c_str(), "a+", stderr)) == NULL)
        {
            tprintf(PRINT_STD, "Cannot open out put file4.\n");
            exit(1);
        }

        fprintf(stderr, " ");

        opt.Mode = Mode;
        vpxt_output_settings(MemLeakCheckParFileStr.c_str(), opt);
        vpxt_run_exe(ProgramEncMemLeakCheckStr.c_str());
        vpxt_run_exe(ProgramDecMemLeakCheckStr.c_str());
    }

    //Create Compression only stop test short.
    if (TestType == COMP_ONLY)
    {
        //Compression only run
        fclose(fp);
        record_test_complete(FileIndexStr, FileIndexOutputChar, TestType);
        return 10;
    }

    int fail = 0;

    tprintf(PRINT_BTH, "\n\nResults:\n\n");

    std::string MemCompressResults = "";
    std::string MemDecompressResults = "";

    if (vpxt_check_mem_state(EncMemLeakCheckTxtStr, MemCompressResults) == -1)
    {
        vpxt_formated_print(RESPRT, "%s not found - Failed",
            EncMemLeakCheckTxtStr.c_str());
        fail = 1;
    }
    else
    {
        if (MemCompressResults.compare(0, 24, "_currently Allocated= 0;") == 0)
        {
            vpxt_formated_print(RESPRT, "Compression Memory Currently "
                "Allocated == 0 - Passed");
            tprintf(PRINT_BTH, "\n");
        }
        else
        {
            vpxt_formated_print(RESPRT, "Compression Memory Currently "
                "Allocated != 0 - %s - Failed", MemCompressResults.c_str());
            tprintf(PRINT_BTH, "\n");
            fail = 1;
        }
    }

    if (vpxt_check_mem_state(DecMemLeakCheckTxtStr, MemDecompressResults) == -1)
    {
        vpxt_formated_print(RESPRT, "%s not found - Failed",
            EncMemLeakCheckTxtStr.c_str());
        fail = 1;
    }
    else
    {
        if (MemDecompressResults.compare(0, 24, "_currently Allocated= 0;") ==0)
        {
            vpxt_formated_print(RESPRT, "Decompression Memory Currently "
                "Allocated == 0 - Passed");
            tprintf(PRINT_BTH, "\n");
        }
        else
        {
            vpxt_formated_print(RESPRT, "Decompression Memory Currently "
                "Allocated != 0 - %s - Failed", MemDecompressResults.c_str());
            tprintf(PRINT_BTH, "\n");
            fail = 1;
        }
    }

    if (fail == 0)
    {
        tprintf(PRINT_BTH, "\nPassed\n");

        if (DeleteIVF)
            vpxt_delete_files(2, MemLeakCheckIVFDECStr.c_str(),
            MemLeakCheckIVFStr.c_str());

        fclose(fp);
        record_test_complete(FileIndexStr, FileIndexOutputChar, TestType);
        return 1;
    }
    else
    {
        tprintf(PRINT_BTH, "\nFailed\n");

        if (DeleteIVF)
            vpxt_delete_files(2, MemLeakCheckIVFDECStr.c_str(),
            MemLeakCheckIVFStr.c_str());

        fclose(fp);
        record_test_complete(FileIndexStr, FileIndexOutputChar, TestType);
        return 0;
    }

    fclose(fp);
    record_test_complete(FileIndexStr, FileIndexOutputChar, TestType);
    return 0;
}