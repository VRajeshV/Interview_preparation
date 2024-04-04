/***************************************************
 * Name    : lib_parser.cpp
 * 
 * DESC    : parse given path for so libs and print
 *           architecture information for each lib
 * 
 * Author  : pavanbobba206@gmail.com
*****************************************************/
#include "lib_parser.h"

/*function to get the architecture information based on machine type
type - machine type
val - string parameter to retrieve architecture specific data
*/
string * get_arch_type( uint16_t type, string * val)
{
   switch(type)
   {
      case EM_M32:      *val = "AT&T WE 32100";
                        break;
      case EM_SPARC:	 	*val = "SUN SPARC";
                        break;
      case EM_386:		*val = "Intel 80386";
                        break;
      case EM_68K:		*val = "Motorola m68k family";
                        break;
      case EM_88K:		*val = "Motorola m88k family";
                        break;
      case EM_860:		*val = "Intel 80860";
                        break;
      case EM_MIPS:		*val = "MIPS R3000 big-endian";
                        break;
      case EM_S370:		*val = "IBM System/370";
                        break;
      case EM_MIPS_RS3_LE:	*val = "MIPS R3000 little-endian";
                           break;
      case EM_PARISC:	*val = "HPPA";
                        break;
      case EM_VPP500:	*val = "Fujitsu VPP500";
                        break;
      case EM_SPARC32PLUS:	*val = "Sun's v8plus";
                        break;
      case EM_960:		*val = "Intel 80960";
                        break;
      case EM_PPC:		*val = "PowerPC";
                        break;
      case EM_PPC64:	   *val = "PowerPC 64-bit";
                        break;
      case EM_S390:		*val = "IBM S390";
                        break;
      case EM_V800:		*val = "NEC V800 series";
                        break;
      case EM_FR20:		*val = "Fujitsu FR20";
                        break;
      case EM_RH32:		*val = "TRW RH-32";
                        break;
      case EM_RCE:		*val = "Motorola RCE";
                        break;
      case EM_ARM:		*val = "ARM";
                        break;
      case EM_FAKE_ALPHA:	*val = "Digital Alpha";
                           break;
      case EM_SH:		   *val = "Hitachi SH";
                        break;
      case EM_SPARCV9:	*val = "SPARC v9 64-bit";
                        break;
      case EM_TRICORE:	*val = "Siemens Tricore";
                        break;
      case EM_ARC:		*val = "Argonaut RISC Core";
                        break;
      case EM_H8_300:	*val = "Hitachi H8/300";
                        break;
      case EM_H8_300H:	*val = "Hitachi H8/300H";
                        break;
      case EM_H8S:		*val = "Hitachi H8S";
                        break;
      case EM_H8_500:	*val = "Hitachi H8/500";
                        break;
      case EM_IA_64:	   *val = "Intel Merced";
                        break;
      case EM_MIPS_X:	*val = "Stanford MIPS-X";
                        break;
      case EM_COLDFIRE:	*val = "Motorola Coldfire";
                        break;
      case EM_68HC12:	*val = "Motorola M68HC12";
                        break;
      case EM_MMA:		*val = "Fujitsu MMA Multimedia Accelerator";
                        break;
      case EM_PCP:		*val = "Siemens PCP";
                        break;
      case EM_NCPU:		*val = "Sony nCPU embeeded RISC";
                        break;
      case EM_NDR1:		*val = "Denso NDR1 microprocessor";
                        break;
      case EM_STARCORE:	*val = "Motorola Start*Core processor";
                        break;
      case EM_ME16:		*val = "Toyota ME16 processor";
                        break;
      case EM_ST100:	   *val = "STMicroelectronic ST100 processor";
                        break;
      case EM_TINYJ:	   *val = "Advanced Logic Corp. Tinyj emb.fam";
                        break;
      case EM_X86_64:	*val = "AMD x86-64 architecture";
                        break;
      case EM_PDSP:		*val = "Sony DSP Processor";
                        break;
      case EM_FX66:		*val = "Siemens FX66 microcontroller";
                        break;
      case EM_ST9PLUS:	*val = "STMicroelectronics ST9+ 8/16 mc";
                        break;
      case EM_ST7:		*val = "STmicroelectronics ST7 8 bit mc";
                        break;
      case EM_68HC16:	*val = "Motorola MC68HC16 microcontroller";
                        break;
      case EM_68HC11:	*val = "Motorola MC68HC11 microcontroller";
                        break;
      case EM_68HC08:	*val = "Motorola MC68HC08 microcontroller";
                        break;
      case EM_68HC05:	*val = "Motorola MC68HC05 microcontroller";
                        break;
      case EM_SVX:		*val = "Silicon Graphics SVx";
                        break;
      case EM_ST19:		*val = "STMicroelectronics ST19 8 bit mc";
                        break;
      case EM_VAX:		*val = "Digital VAX";
                        break;
      case EM_CRIS:		*val = "Axis Communications 32-bit embedded processor";
                        break;
      case EM_JAVELIN:	*val = "Infineon Technologies 32-bit embedded processor";
                        break;
      case EM_FIREPATH:	*val = "Element 14 64-bit DSP Processor";
                        break;
      case EM_ZSP:		*val = "LSI Logic 16-bit DSP Processor";
                        break;
      case EM_MMIX:		*val = "Donald Knuth's educational 64-bit processor";
                        break;
      case EM_HUANY:	   *val = "Harvard University machine-independent object files";
                        break;
      case EM_PRISM:	   *val = "SiTera Prism";
                        break;
      case EM_AVR:		*val = "Atmel AVR 8-bit microcontroller";
                        break;
      case EM_FR30:		*val = "Fujitsu FR30";
                        break;
      case EM_D10V:		*val = "Mitsubishi D10V";
                        break;
      case EM_D30V:		*val = "Mitsubishi D30V";
                        break;
      case EM_V850:		*val = "NEC v850";
                        break;
      case EM_M32R:		*val = "Mitsubishi M32R";
                        break;
      case EM_MN10300:	*val = "Matsushita MN10300";
                        break;
      case EM_MN10200:	*val = "Matsushita MN10200";
                        break;
      case EM_PJ:		   *val = "picoJava";
                        break;
      case EM_OPENRISC:	*val = "OpenRISC 32-bit embedded processor";
                        break;
      case EM_ARC_A5:	*val = "ARC Cores Tangent-A5";
                        break;
      case EM_XTENSA:	*val = "Tensilica Xtensa Architecture";
                        break;
      case EM_ALTERA_NIOS2: *val = "Altera Nios II";
                            break;
      case EM_AARCH64:	*val = "ARM AARCH64";
                        break;
      case EM_TILEPRO:	*val = "Tilera TILEPro";
                        break;
      case EM_MICROBLAZE:	*val = "Xilinx MicroBlaze";
                        break;
      case EM_TILEGX:	*val = "Tilera TILE-Gx";
                        break;
      default: *val = "not a valid type";
   }

   return val;
}

int main(int argc, char *argv[])
{
   ifstream file;
   uint16_t f_type, m_type;
   string lib_path, str_arch;
   unsigned char buf[20];
   map<string, string> print_data;
   DIR * dir = NULL;
   /*variable to return number of valid libraries count*/
   unsigned int lib_count = 0;
   struct dirent * file_data = NULL;
   /*ELF Magic first 4 bytes: 0x7f, 'E', 'L', 'F'*/
   unsigned char elf_magic[4] = {0x7f, 0x45, 0x4c, 0x46};

   /*Reading the user input path from console*/
   cout<<"enter the path:"<<endl;
   getline(cin, lib_path);

   /*opening the path provided by user*/
   dir = opendir(lib_path.c_str());
   if(dir != NULL)
   { 
      /*changing the present working directory to the path provided by user*/
      chdir(lib_path.c_str());

      /*reading the entries in the directory*/
      file_data = readdir(dir);
      while (file_data != NULL)
      {
         /*opening the file*/
         file.open(file_data->d_name);
         if(file)
         {
            memset(buf, 0, sizeof(buf));

            /*Reading first 20 bytes of ELF header into buffer*/
            file.read((char *)buf, sizeof(buf));

            /*validating the file having valid ELF header*/
            if(!memcmp(elf_magic, buf, sizeof(elf_magic)))
            {
                f_type = 0;
                m_type = 0;
                
                /*checking architecture byte order for which the file generated for*/
                if(buf[5] == ELFDATA2LSB)
                {
                  /*concatinating bytes to find file type and machine name in little endian architecture*/
                  f_type = (((buf[17] | f_type)<<8) | buf[16]);
                  m_type = (((buf[19] | m_type)<<8) | buf[18]);
                }
                else if(buf[5] == ELFDATA2MSB)
                {
                  /*concatinating bytes to find file type and machine name in big endian architecture*/
                  f_type = (((buf[16] | f_type)<<8) | buf[17]);
                  m_type = (((buf[18] | m_type)<<8) | buf[19]);
                }
                /*validating whether the existing file is a shared object or not*/
                if(f_type == ET_DYN)
                {
                   /*retrieving the architecture specific info in string format*/
                   get_arch_type(m_type, &str_arch);
                   print_data.insert({file_data->d_name, str_arch});
                   lib_count++;
                }
            }
            file.close();
         }
         file_data = readdir(dir);
      }

      closedir(dir);  
      cout<<"Total number of libraries:"<<lib_count<<"\n"<<endl;
      cout<<"File"<<string(SPACE - 4, ' ')<<"ArchType\n"<<endl;
      for(auto itr=print_data.begin(); itr != print_data.end(); ++itr)
         cout<<itr->first<<string((SPACE - (itr->first.length())), ' ')<<itr->second<<'\n';
   }
   else
   {
       perror("path: ");
   }

   return 0;
}