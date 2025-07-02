static int get_mode()
{
	FILE *fp;
	char buf[3072];
	char *pos;
	
	fp = fopen("/var/pps_persist/pateo_property", "r");
	if(fp)
	{
		fread(buf, 1, sizeof(buf),fp);
		pos = strstr(buf, "apa_avm_config:n:");
		if(pos){
             SERR("sunpeng max96712a apa_avm_config pos = %s",pos);
			return atoi(pos+17);
		}
		fclose(fp);
    }else
    {
      SERR("sunpeng max96712a apa_avm_config fopen file ");
    }
	
	return -1;
}