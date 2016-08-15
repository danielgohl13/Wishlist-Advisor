<?php
$userNickname = $argv[1];
$steamUrl = 'http://steamcommunity.com/id/{user_id}/wishlist/';

function httpRequest($url){
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    $output = curl_exec($ch);
    curl_close($ch);
    return $output;
}

$document = httpRequest(str_replace('{user_id}', $userNickname, $steamUrl));

$dom = new DOMDocument(null, 'UTF-8');
@$dom->loadHTML($document);
$list = $dom->getElementById('wishlist_items')->childNodes;
$games = array();
$count = 1;

foreach ($list as $item) {

    if(!($item instanceof DOMElement)) continue;
    $gameName = trim($item->getElementsByTagName('h4')->item(0)->nodeValue);
    $gamePrice = 0;

    $divs = $item->getElementsByTagName('div');
    foreach ($divs as $i) {
        if($i->getAttribute('class') == 'price'){
            $gamePrice = (float) str_replace(array('R$ ', ','), array('', '.'), trim($i->nodeValue));
            break;
        }
    };

    if($gamePrice > 0){
        $games[] = array(
            'order' => $count++,
            'name' => $gameName,
            'price' => $gamePrice
        );
    }
    else{
        $count++;
    }
}

echo "Jogos da lista:\n";
foreach ($games as $item) {
    echo $item['order'], " - ", $item['name'], " - ", $item['price'], "\n";
}

echo "\nA lista foi salva no arquivo \"", $userNickname, ".json\".\n";
file_put_contents($userNickname.'.json', json_encode($games));
