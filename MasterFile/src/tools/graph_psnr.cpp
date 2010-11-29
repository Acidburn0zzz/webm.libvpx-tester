#include "vpxt_test_declarations.h"

int graph_psnr(int argc, char *argv[], string WorkingDir, string FilesAr[], int TestType)
{
    if (argc < 6 || argc > 8)
    {
        printf("\n"
               "  GraphPSNR\n\n"
               "    <Inputfile 1>\n"
               "    <Starting Bit Rate>\n"
               "    <Ending Bit Rate>\n"
               "    <Bit Rate Step>\n"
               "    <Optional - Par Input>\n"

               "\n");
        return 0;
    }

    ////////////Formatting Test Specific Directory////////////
    char WorkingDir2[255] = "";
    char WorkingDir3[255] = "";
    char *MyDir = "GraphPSNR";
    string MainDirString = "";
    char File1[255] = "";

    snprintf(WorkingDir2, 255, "%s", WorkingDir.c_str());

    int v = 0;

    while (WorkingDir2[v] != '\"')
    {
        WorkingDir3[v] = WorkingDir2[v];
        v++;
    }

    WorkingDir3[v] = slashChar();
    WorkingDir3[v+1] = '\0';
    string WorkingDirString = WorkingDir3;
    WorkingDirString.append(MyDir);
    WorkingDirString.append(slashCharStr());
    WorkingDirString.append(FilesAr[0]);
    WorkingDirString.erase(WorkingDirString.length() - 1, 1);

    string CreateDir2 = WorkingDirString;
    CreateDir2.insert(0, "md \"");
    vpxt_make_dir_vpx(CreateDir2.c_str());

    /////////////OutPutfile////////////
    string TextfileString = WorkingDirString;

    TextfileString.append(slashCharStr());
    TextfileString.append(MyDir);
    string OutPutStr = TextfileString;
    TextfileString.append(".txt");

    OutPutStr.append("_");

    FILE *fp;

    if ((fp = freopen(TextfileString.c_str(), "w", stderr)) == NULL)
    {
        printf("Cannot open out put file: %s\n", TextfileString.c_str());
        exit(1);
    }

    ////////////////////////////////
    //////////////////////////////////////////////////////////

    if (TestType == 1)
    {
        print_header_full_test(argc, argv, WorkingDir3);
    }

    if (TestType == 2)
    {
        print_header_compression_only(argc, argv, WorkingDir3);
    }

    if (TestType == 3)
    {
        print_header_test_only(argc, argv, WorkingDirString);
    }

    tprintf("Graph PSNR\n");

    char *input = argv[2];
    int FirstBitRate = atoi(argv[3]);
    int LastBitRate = atoi(argv[4]);
    int BitRateStep = atoi(argv[5]);
    char *ParFile = argv[6];

    int speed = 0;

    char  FileNameChar[255];
    vpxt_file_name(input, FileNameChar, 0);
    string InputName = FileNameChar;
    InputName.resize(InputName.length() - 4, ' ');
    OutPutStr.append(InputName.c_str());
    string ParFileOut = OutPutStr;
    OutPutStr.append("_TBR");

    VP8_CONFIG opt;
    vpxt_default_parameters(opt);

    double PSNRArr[100];
    double SSIMArr[100];
    double DataRateArr[100];
    unsigned int EncTimeArr[100];
    unsigned int DecTimeArr[100];


    char *CompressString = "Graph PSNR";

    if (argc > 6)
    {
        opt = vpxt_input_settings(ParFile);
    }

    opt.target_bandwidth = FirstBitRate;

    ///////////output Par file////////////////////
    ParFileOut.append("_ParameterFile.txt");
    char ParFileOutChar[255];
    snprintf(ParFileOutChar, 255, "%s", ParFileOut.c_str());
    vpxt_output_settings(ParFileOutChar, opt);
    ///////////////////////////////////////////////

    int x = 0;
    int DoONce = 0;

    while (opt.target_bandwidth <= LastBitRate)
    {
        if (opt.target_bandwidth == LastBitRate && DoONce == 0)
        {
            DoONce = 1;
        }

        string OutPutStr2 = OutPutStr;
        char TBChar[8];
        vpxt_itoa_custom(opt.target_bandwidth, TBChar, 10);
        OutPutStr2.append(TBChar);
        string OutPutStr3 = OutPutStr2;
        OutPutStr3.append("_Dec");
        OutPutStr2.append(".ivf");
        OutPutStr3.append(".ivf");

        char outputChar[255];
        snprintf(outputChar, 255, "%s", OutPutStr2.c_str());

        char outputChar2[255];
        snprintf(outputChar2, 255, "%s", OutPutStr3.c_str());

        unsigned int cpu_tick1 = 0;
        EncTimeArr[x] = vpxt_time_compress_ivf_to_ivf(input, outputChar , speed, opt.target_bandwidth, opt, CompressString, 0, 0, cpu_tick1);

        if (EncTimeArr[x] == -1)
        {
            fclose(fp);
            record_test_complete(MainDirString, File1, TestType);
            return 2;
        }

        unsigned int cpu_tick2 = 0;
        DecTimeArr[x] = vpxt_time_decompress_ivf_to_ivf(outputChar, outputChar2, cpu_tick2);

        if (DecTimeArr[x] == -1)
        {
            fclose(fp);
            record_test_complete(MainDirString, File1, TestType);
            return 2;
        }

        double ssimnumber = 0;
        PSNRArr[x] = vpxt_ivf_psnr(input, outputChar, 0, 2, 1, &ssimnumber);
        SSIMArr[x] = ssimnumber;
        DataRateArr[x] = vpxt_ivf_data_rate(outputChar, 1);
        x++;



        opt.target_bandwidth = opt.target_bandwidth + BitRateStep;

        if (opt.target_bandwidth > LastBitRate && DoONce == 0)
        {
            opt.target_bandwidth = LastBitRate;
            DoONce = 1;
        }

    }

    int ArrSize = x;
    x = 0;

    tprintf("\n\n");

    while (x < ArrSize)
    {
        tprintf(" DataRate: %.2f PSNR: %.2f SSIM: %.2f EncodeTime: %i \n DecodeTime: %i\n", DataRateArr[x], PSNRArr[x], SSIMArr[x], EncTimeArr[x], DecTimeArr[x]);
        x++;
    }

    x = 0;

    tprintf("\n\nDataRate\n\n");

    while (x < ArrSize)
    {
        tprintf("%.2f\n", DataRateArr[x]);
        x++;
    }

    x = 0;

    tprintf("\nPSNR\n\n");

    while (x < ArrSize)
    {
        tprintf("%.2f\n", PSNRArr[x]);
        x++;
    }

    x = 0;

    tprintf("\nSSIM\n\n");

    while (x < ArrSize)
    {
        tprintf("%.2f\n", SSIMArr[x]);
        x++;
    }

    x = 0;

    tprintf("\nEncodeTime\n\n");

    while (x < ArrSize)
    {
        tprintf("%i\n", EncTimeArr[x]);
        x++;
    }

    x = 0;

    tprintf("\nDecodeTime\n\n");

    while (x < ArrSize)
    {
        tprintf("%i\n", DecTimeArr[x]);
        x++;
    }

    fclose(fp);
    return 4;

}