<?php
namespace Home\Service;

/**
 * 项目管理类
 */
class ProjectService{

    const ASSETS = 'assets';

    /**
     * 项目目录
     */
    static $project_basic_path = 'E:\AndroidProject\\';

    static $project_default_config = 'E:\AndroidProject\Demo';

    static $project_default_conf = 'D:\build_tool\buildtools\conf\\';

    static $project_default_apk_path = 'D:\build_tool\buildtools\output\\';

    /**
     * 创建新项目
     */
    public function create($project_name){
        $path = self::$project_basic_path . $project_name;
        if(!file_exists($path)){
            $this->copy_dir(self::$project_default_config, $path);
            return true;
        }else{
            E('已经存在此项目');
        }
    }

    public function init_project($project_name, $default = true){
    }

    public function get_project_path($project)
    {
        return self::$project_basic_path . $project . '\\';
    }

    public function get_project_assets_path($project, $version)
    {
        return self::$project_basic_path . $project . '\\' . $version . self::ASSETS;
    }

    public function get_project_conf_path($project, $version){
        return self::$project_default_conf . $project . '\\' . $version . '.json';
    }

    public function get_apk_path($project, $version){
        return self::$project_default_apk_path . $project . $version . '.apk';
    }

    public function create_conf_json($project, $version){
        $array['build_steup'] = array();
        $array['project_name'] = $project . $version;
        $array['project_res'] = $this->get_project_path($project) . 'res';
        $array['project_src'] = $this->get_project_path($project) . 'src';
        $array['project_xml'] = $this->get_project_path($project) . 'AndroidManifest.xml';
        $array['project_assets'] = $this->get_project_assets_path($project, $version);
        $array['project_libs'] = $this->get_project_path($project) . 'libs';
        $array['project_path'] = $this->get_project_path($project);
        $array['library_project'] = array();
        $json = json_encode($array);
        $file = $this->get_project_conf_path($project, $version);
        $ret  = file_put_contents($file, $json);
        return $file;
    }

    public function build_apk($conf) {
        $result = array();
        $exit_code = 0;
        //D:\\build_tool\\buildtools\\majian.json
        $ret = exec("D:\build_tool\buildtools\buildtools.exe -build=D:\\build_tool\\buildtools\\build.ini -union={$conf}",$result,$exit_code);
        // var_dump($ret);
        // var_dump($result);
        // var_dump($exit_code);
        $data['code'] = true;
        $data['desc'] = $result;  //打包日志  todo
        if($exit_code != 0) {
            $data['result'] = false;
        }
        return $data;
    }

    private function copy_dir($src,$dst) {
        $dir = opendir($src);
        mkdir($dst);
        while(false !== ( $file = readdir($dir)) ) {
          if (( $file != '.' ) && ( $file != '..' )) {
            if ( is_dir($src . '/' . $file) ) {
              copy_dir($src . '/' . $file,$dst . '/' . $file);
              continue;
            }
            else {
              copy($src . '/' . $file,$dst . '/' . $file);
            }
          }
        }
        closedir($dir);
    }

    public function ZipArchive($src,$dst){
        $zip = new \ZipArchive;  
        $res = $zip->open($src);
        if ($res === TRUE) { 
            $zip->extractTo($dst);
            $zip->close();
            return true;
        }else { 
            return false;
        }
    }

    

}