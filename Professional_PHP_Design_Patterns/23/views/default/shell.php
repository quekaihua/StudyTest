/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2015/12/14
 * Time: 11:54
 */
<!DOCTYPE>

<html xlmns="http://www.w3.org/1999/xhtml" >
<head>
    <meta http-equiv="content-type" content="text/html;charset=utf-8"/>
    <link rel="stylesheet" type="text/css" href="/assets/main.css"/>
    <title>Acme Company Contact Manager</title>
    <script type="text/javascript" src="/assets/jquery-1.3.2.min.js"></script>
</head>
<body>
    <div id="header">
        <?php echo view::show('standard/header');?>
    </div>
    <div id="body">
        <?php echo $view['body']?>
    </div>
    <div id="footer">
        <?php echo view::show('standard/footer');?>
    </div>
</body>